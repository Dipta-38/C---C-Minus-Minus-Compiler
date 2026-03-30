%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char *s);

FILE *output_file = NULL;
FILE *token_file = NULL;

int global_arr_length = 0;

void emit_builtin_functions();
void emit_slice_functions();

%}

%union {
    int ival;
    double fval;
    char *sval;
}

/* Token declarations */
%token <sval> ID STRING CHAR
%token <ival> INT
%token <fval> FLOAT

/* Keywords */
%token LET DEC STR_TYPE CHR_TYPE BUL_TYPE NUL_TYPE
%token CLS ENM TYP CON
%token IF_COLON ELIF_COLON WHILE_COLON DO ELSE
%token BRK CNT RET
%token OUT INP
%token AND OR NOT
%token MAIN_FUNC
%token LET_PTR PRINT_SLICE FREE_SLICE

/* Built-in functions */
%token GCD_FUNC ISPRIME_FUNC FACTORIAL_FUNC ISPALINDROME_FUNC
%token SUM_FUNC MAX_FUNC MIN_FUNC AVG_FUNC SWAP_FUNC

/* Operators */
%token POW_EXPR POW_OP
%token GE LE EQ NE INC DECR
%token PLUS MINUS MUL DIV MOD ASSIGN
%token LT GT BITAND BITOR BITXOR BITNOT LSHIFT RSHIFT

/* Delimiters */
%token LPAREN RPAREN LBRACE RBRACE SEMI COMMA COLON
%token LBRACKET RBRACKET DOT

/* Precedence and associativity */
%right ASSIGN
%left OR
%left AND
%left BITOR
%left BITXOR
%left BITAND
%left EQ NE
%left LT GT LE GE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left MUL DIV MOD
%right NOT BITNOT
%right POW_OP
%left LPAREN RPAREN LBRACKET RBRACKET

%type <sval> type_specifier expression primary_expression
%type <sval> postfix_expression unary_expression multiplicative_expression
%type <sval> additive_expression relational_expression equality_expression
%type <sval> logical_and_expression logical_or_expression assignment_expression
%type <sval> statement compound_statement declaration
%type <sval> expression_statement if_statement while_statement do_while_statement jump_statement
%type <sval> argument_list

%start program

%%

program
    : MAIN_FUNC LBRACE {
        fprintf(output_file, "int main() {\n");
        if (global_arr_length > 0) {
            fprintf(output_file, "    int arr_length = %d;\n", global_arr_length);
        }
    } statement_list RBRACE {
        fprintf(output_file, "}\n");
    }
    ;

statement_list
    : /* empty */
    | statement_list statement
    ;

statement
    : declaration
    | expression_statement
    | compound_statement
    | if_statement
    | while_statement
    | do_while_statement
    | jump_statement
    ;

declaration
    : type_specifier ID SEMI {
        fprintf(output_file, "    %s %s;\n", $1, $2);
        free($1); free($2);
    }
    | type_specifier ID ASSIGN expression SEMI {
        fprintf(output_file, "    %s %s = %s;\n", $1, $2, $4);
        free($1); free($2); free($4);
    }
    | type_specifier ID LBRACKET RBRACKET ASSIGN LBRACE argument_list RBRACE SEMI {
        fprintf(output_file, "    %s %s[] = {%s};\n", $1, $2, $7);
        free($1); free($2); free($7);
    }
    | type_specifier ID LBRACKET INT RBRACKET SEMI {
        fprintf(output_file, "    %s %s[%d];\n", $1, $2, $4);
        free($1); free($2);
    }
    | LET_PTR ID ASSIGN expression SEMI {
        fprintf(output_file, "    int* %s = %s;\n", $2, $4);
        free($2); free($4);
    }
    ;

type_specifier
    : LET { $$ = strdup("int"); }
    | DEC { $$ = strdup("double"); }
    | STR_TYPE { $$ = strdup("const char*"); }
    | CHR_TYPE { $$ = strdup("char"); }
    | BUL_TYPE { $$ = strdup("bool"); }
    | NUL_TYPE { $$ = strdup("void"); }
    | CLS { $$ = strdup("struct"); }
    | ENM { $$ = strdup("enum"); }
    ;

expression_statement
    : SEMI
    | expression SEMI {
        fprintf(output_file, "    %s;\n", $1);
        free($1);
    }
    ;

compound_statement
    : LBRACE statement_list RBRACE
    ;

if_statement
    : IF_COLON expression LBRACE statement_list RBRACE {
        fprintf(output_file, "    if (%s) {\n", $2);
        fprintf(output_file, "    }\n");
        free($2);
    }
    | IF_COLON expression LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE {
        fprintf(output_file, "    if (%s) {\n", $2);
        fprintf(output_file, "    } else {\n");
        fprintf(output_file, "    }\n");
        free($2);
    }
    | IF_COLON expression LBRACE statement_list RBRACE ELIF_COLON expression LBRACE statement_list RBRACE {
        fprintf(output_file, "    if (%s) {\n", $2);
        fprintf(output_file, "    } else if (%s) {\n", $7);
        fprintf(output_file, "    }\n");
        free($2);
        free($7);
    }
    ;

while_statement
    : WHILE_COLON expression LBRACE statement_list RBRACE {
        fprintf(output_file, "    while (%s) {\n", $2);
        fprintf(output_file, "    }\n");
        free($2);
    }
    ;

do_while_statement
    : DO LBRACE statement_list RBRACE WHILE_COLON expression SEMI {
        fprintf(output_file, "    do {\n");
        fprintf(output_file, "    } while (%s);\n", $6);
        free($6);
    }
    ;

jump_statement
    : RET expression SEMI {
        fprintf(output_file, "    return %s;\n", $2);
        free($2);
    }
    | RET SEMI {
        fprintf(output_file, "    return;\n");
    }
    | BRK SEMI {
        fprintf(output_file, "    break;\n");
    }
    | CNT SEMI {
        fprintf(output_file, "    continue;\n");
    }
    ;

expression
    : assignment_expression { $$ = $1; }
    ;

assignment_expression
    : logical_or_expression { $$ = $1; }
    | unary_expression ASSIGN assignment_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s = %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    ;

logical_or_expression
    : logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s || %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    ;

logical_and_expression
    : equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s && %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s == %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    | equality_expression NE relational_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s != %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression LT additive_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s < %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    | relational_expression GT additive_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s > %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    | relational_expression LE additive_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s <= %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    | relational_expression GE additive_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s >= %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression PLUS multiplicative_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s + %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    | additive_expression MINUS multiplicative_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s - %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    ;

multiplicative_expression
    : unary_expression { $$ = $1; }
    | multiplicative_expression MUL unary_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s * %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    | multiplicative_expression DIV unary_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s / %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    | multiplicative_expression MOD unary_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s %% %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
    | INC unary_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "++%s", $2);
        $$ = strdup(buf);
        free($2);
    }
    | DECR unary_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "--%s", $2);
        $$ = strdup(buf);
        free($2);
    }
    | NOT unary_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "!%s", $2);
        $$ = strdup(buf);
        free($2);
    }
    | MINUS unary_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "-%s", $2);
        $$ = strdup(buf);
        free($2);
    }
    | BITAND unary_expression {
        char buf[512];
        snprintf(buf, sizeof(buf), "&%s", $2);
        $$ = strdup(buf);
        free($2);
    }
    ;

postfix_expression
    : primary_expression { $$ = $1; }
    | postfix_expression LBRACKET expression RBRACKET {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s[%s]", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    | postfix_expression LPAREN RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s()", $1);
        $$ = strdup(buf);
        free($1);
    }
    | postfix_expression LPAREN argument_list RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s(%s)", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    | postfix_expression INC {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s++", $1);
        $$ = strdup(buf);
        free($1);
    }
    | postfix_expression DECR {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s--", $1);
        $$ = strdup(buf);
        free($1);
    }
    | OUT LPAREN argument_list RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "printf(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | INP LPAREN argument_list RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "scanf(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | PRINT_SLICE LPAREN expression RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "print_int_slice(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | FREE_SLICE LPAREN expression RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "free_int_slice(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | GCD_FUNC LPAREN argument_list RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "gcd(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | ISPRIME_FUNC LPAREN expression RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "isprime(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | FACTORIAL_FUNC LPAREN expression RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "factorial(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | ISPALINDROME_FUNC LPAREN expression RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "ispalindrome(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | SUM_FUNC LPAREN argument_list RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "sum(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | MAX_FUNC LPAREN argument_list RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "max(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | MIN_FUNC LPAREN argument_list RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "min(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | AVG_FUNC LPAREN argument_list RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "avg(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    | SWAP_FUNC LPAREN argument_list RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "swap(%s)", $3);
        $$ = strdup(buf);
        free($3);
    }
    ;

primary_expression
    : ID { $$ = strdup($1); }
    | INT {
        char buf[64];
        snprintf(buf, sizeof(buf), "%d", $1);
        $$ = strdup(buf);
    }
    | FLOAT {
        char buf[64];
        snprintf(buf, sizeof(buf), "%f", $1);
        $$ = strdup(buf);
    }
    | STRING { $$ = strdup($1); }
    | CHAR { $$ = strdup($1); }
    | LPAREN expression RPAREN {
        char buf[512];
        snprintf(buf, sizeof(buf), "(%s)", $2);
        $$ = strdup(buf);
        free($2);
    }
    ;

argument_list
    : expression {
        $$ = strdup($1);
        free($1);
    }
    | argument_list COMMA expression {
        char buf[1024];
        snprintf(buf, sizeof(buf), "%s, %s", $1, $3);
        $$ = strdup(buf);
        free($1); free($3);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s near '%s'\n", yylineno, s, yytext);
}

void emit_builtin_functions() {
    fprintf(output_file, "/* Built-in Function Implementations */\n\n");
    
    fprintf(output_file, "int gcd(int a, int b) {\n");
    fprintf(output_file, "    while (b != 0) { int temp = b; b = a %% b; a = temp; }\n");
    fprintf(output_file, "    return a;\n}\n\n");
    
    fprintf(output_file, "bool isprime(int n) {\n");
    fprintf(output_file, "    if (n <= 1) return false;\n");
    fprintf(output_file, "    if (n <= 3) return true;\n");
    fprintf(output_file, "    if (n %% 2 == 0 || n %% 3 == 0) return false;\n");
    fprintf(output_file, "    for (int i = 5; i * i <= n; i += 6)\n");
    fprintf(output_file, "        if (n %% i == 0 || n %% (i + 2) == 0) return false;\n");
    fprintf(output_file, "    return true;\n}\n\n");
    
    fprintf(output_file, "long long factorial(int n) {\n");
    fprintf(output_file, "    long long result = 1;\n");
    fprintf(output_file, "    for (int i = 2; i <= n; i++) result *= i;\n");
    fprintf(output_file, "    return result;\n}\n\n");
    
    fprintf(output_file, "bool ispalindrome(const char* str) {\n");
    fprintf(output_file, "    int len = strlen(str);\n");
    fprintf(output_file, "    for (int i = 0; i < len / 2; i++)\n");
    fprintf(output_file, "        if (str[i] != str[len - i - 1]) return false;\n");
    fprintf(output_file, "    return true;\n}\n\n");
    
    fprintf(output_file, "int sum(int arr[], int size) {\n");
    fprintf(output_file, "    int total = 0;\n");
    fprintf(output_file, "    for (int i = 0; i < size; i++) total += arr[i];\n");
    fprintf(output_file, "    return total;\n}\n\n");
    
    fprintf(output_file, "int max(int arr[], int size) {\n");
    fprintf(output_file, "    int m = arr[0];\n");
    fprintf(output_file, "    for (int i = 1; i < size; i++)\n");
    fprintf(output_file, "        if (arr[i] > m) m = arr[i];\n");
    fprintf(output_file, "    return m;\n}\n\n");
    
    fprintf(output_file, "int min(int arr[], int size) {\n");
    fprintf(output_file, "    int m = arr[0];\n");
    fprintf(output_file, "    for (int i = 1; i < size; i++)\n");
    fprintf(output_file, "        if (arr[i] < m) m = arr[i];\n");
    fprintf(output_file, "    return m;\n}\n\n");
    
    fprintf(output_file, "double avg(int arr[], int size) {\n");
    fprintf(output_file, "    return size ? (double)sum(arr, size) / size : 0.0;\n}\n\n");
    
    fprintf(output_file, "void swap(int* a, int* b) {\n");
    fprintf(output_file, "    int t = *a; *a = *b; *b = t;\n}\n\n");
}

void emit_slice_functions() {
    fprintf(output_file, "int* int_slice_step(int* arr, int start, int stop, int step, int length) {\n");
    fprintf(output_file, "    if (step < 0 && stop == -1) {\n");
    fprintf(output_file, "        if (start < 0) start = length + start;\n");
    fprintf(output_file, "        if (start < 0) start = -1;\n");
    fprintf(output_file, "        else if (start >= length) start = length - 1;\n");
    fprintf(output_file, "        int slice_length = (start + 1) / (-step);\n");
    fprintf(output_file, "        if ((start + 1) %% (-step) != 0) slice_length++;\n");
    fprintf(output_file, "        if (slice_length <= 0) {\n");
    fprintf(output_file, "            int* result = (int*)malloc(sizeof(int));\n");
    fprintf(output_file, "            if (result) result[0] = 0;\n");
    fprintf(output_file, "            return result;\n");
    fprintf(output_file, "        }\n");
    fprintf(output_file, "        int* result = (int*)malloc((slice_length + 1) * sizeof(int));\n");
    fprintf(output_file, "        if (!result) return NULL;\n");
    fprintf(output_file, "        result[0] = slice_length;\n");
    fprintf(output_file, "        for (int i = 0; i < slice_length; i++) {\n");
    fprintf(output_file, "            result[i + 1] = arr[start + i * step];\n");
    fprintf(output_file, "        }\n");
    fprintf(output_file, "        return result;\n");
    fprintf(output_file, "    }\n");
    fprintf(output_file, "    if (step == 0) { printf(\"Error: Step cannot be zero\\n\"); return NULL; }\n");
    fprintf(output_file, "    if (start < 0) start = length + start;\n");
    fprintf(output_file, "    if (stop < 0) stop = length + stop;\n");
    fprintf(output_file, "    if (step > 0) {\n");
    fprintf(output_file, "        if (start < 0) start = 0;\n");
    fprintf(output_file, "        else if (start > length) start = length;\n");
    fprintf(output_file, "        if (stop < 0) stop = 0;\n");
    fprintf(output_file, "        else if (stop > length) stop = length;\n");
    fprintf(output_file, "    } else {\n");
    fprintf(output_file, "        if (start < 0) start = -1;\n");
    fprintf(output_file, "        else if (start >= length) start = length - 1;\n");
    fprintf(output_file, "        if (stop < 0) stop = -1;\n");
    fprintf(output_file, "        else if (stop > length) stop = length;\n");
    fprintf(output_file, "    }\n");
    fprintf(output_file, "    if ((step > 0 && start >= stop) || (step < 0 && start <= stop)) {\n");
    fprintf(output_file, "        int* result = (int*)malloc(sizeof(int));\n");
    fprintf(output_file, "        if (result) result[0] = 0;\n");
    fprintf(output_file, "        return result;\n");
    fprintf(output_file, "    }\n");
    fprintf(output_file, "    int slice_length;\n");
    fprintf(output_file, "    if (step > 0) {\n");
    fprintf(output_file, "        slice_length = (stop - start + step - 1) / step;\n");
    fprintf(output_file, "    } else {\n");
    fprintf(output_file, "        slice_length = (start - stop - 1) / (-step) + 1;\n");
    fprintf(output_file, "    }\n");
    fprintf(output_file, "    if (slice_length <= 0) {\n");
    fprintf(output_file, "        int* result = (int*)malloc(sizeof(int));\n");
    fprintf(output_file, "        if (result) result[0] = 0;\n");
    fprintf(output_file, "        return result;\n");
    fprintf(output_file, "    }\n");
    fprintf(output_file, "    int* result = (int*)malloc((slice_length + 1) * sizeof(int));\n");
    fprintf(output_file, "    if (!result) return NULL;\n");
    fprintf(output_file, "    result[0] = slice_length;\n");
    fprintf(output_file, "    for (int i = 0; i < slice_length; i++) {\n");
    fprintf(output_file, "        result[i + 1] = arr[start + i * step];\n");
    fprintf(output_file, "    }\n");
    fprintf(output_file, "    return result;\n");
    fprintf(output_file, "}\n\n");
    
    fprintf(output_file, "void print_int_slice(int* slice) {\n");
    fprintf(output_file, "    if (!slice) { printf(\"[NULL]\\n\"); return; }\n");
    fprintf(output_file, "    if (slice[0] == 0) { printf(\"[]\\n\"); return; }\n");
    fprintf(output_file, "    printf(\"[\");\n");
    fprintf(output_file, "    for (int i = 1; i <= slice[0]; i++) {\n");
    fprintf(output_file, "        printf(\"%%d\", slice[i]);\n");
    fprintf(output_file, "        if (i < slice[0]) printf(\", \");\n");
    fprintf(output_file, "    }\n");
    fprintf(output_file, "    printf(\"]\\n\");\n");
    fprintf(output_file, "}\n\n");
    
    fprintf(output_file, "void free_int_slice(int* slice) {\n");
    fprintf(output_file, "    if (slice) free(slice);\n");
    fprintf(output_file, "}\n\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.cmm>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Cannot open input file");
        return 1;
    }

    output_file = fopen("out.c", "w");
    if (!output_file) {
        perror("Cannot create output file");
        fclose(yyin);
        return 1;
    }

    token_file = fopen("tokens.txt", "w");
    if (!token_file) {
        perror("Cannot create token file");
        fclose(yyin);
        fclose(output_file);
        return 1;
    }

    // Write C headers
    fprintf(output_file, "#include <stdio.h>\n");
    fprintf(output_file, "#include <stdbool.h>\n");
    fprintf(output_file, "#include <math.h>\n");
    fprintf(output_file, "#include <string.h>\n");
    fprintf(output_file, "#include <stdlib.h>\n\n");

    // Write function prototypes
    fprintf(output_file, "// C-- built-in functions\n");
    fprintf(output_file, "int gcd(int a, int b);\n");
    fprintf(output_file, "bool isprime(int n);\n");
    fprintf(output_file, "long long factorial(int n);\n");
    fprintf(output_file, "bool ispalindrome(const char* str);\n");
    fprintf(output_file, "int sum(int arr[], int size);\n");
    fprintf(output_file, "int max(int arr[], int size);\n");
    fprintf(output_file, "int min(int arr[], int size);\n");
    fprintf(output_file, "double avg(int arr[], int size);\n");
    fprintf(output_file, "void swap(int* a, int* b);\n");
    fprintf(output_file, "int* int_slice_step(int* arr, int start, int stop, int step, int length);\n");
    fprintf(output_file, "void print_int_slice(int* slice);\n");
    fprintf(output_file, "void free_int_slice(int* slice);\n");
    fprintf(output_file, "#define __internal_slice(a,start,stop,step) int_slice_step(a,start,stop,step,sizeof(a)/sizeof(a[0]))\n\n");

    // Write implementations
    emit_builtin_functions();
    emit_slice_functions();

    // Parse
    int result = yyparse();

    fclose(token_file);
    fclose(output_file);
    fclose(yyin);

    if (result == 0) {
        printf("Compilation successful! Output: out.c\n");
    } else {
        printf("Compilation failed with errors.\n");
    }

    return result;
}