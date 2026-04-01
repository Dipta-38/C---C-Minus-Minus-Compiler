%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char *s);

ASTNode *program_ast = NULL;
FILE *output_file = NULL;
FILE *token_file = NULL;

int global_arr_length = 0;

%}

%union {
    int ival;
    double fval;
    char *sval;
    ASTNode *ast;
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
%token POW_OP
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

%type <ast> program statement_list statement declaration type_specifier
%type <ast> expression_statement compound_statement selection_statement
%type <ast> iteration_statement jump_statement expression
%type <ast> assignment_expression logical_or_expression logical_and_expression
%type <ast> equality_expression relational_expression additive_expression
%type <ast> multiplicative_expression unary_expression postfix_expression
%type <ast> primary_expression argument_list slice_expression

%start program

%%

program
    : MAIN_FUNC LBRACE statement_list RBRACE {
        program_ast = create_program_node($3);
    }
    ;

statement_list
    : /* empty */ { $$ = NULL; }
    | statement_list statement {
        $$ = create_statement_list_node($1, $2);
    }
    ;

statement
    : declaration { $$ = $1; }
    | expression_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement { $$ = $1; }
    ;

declaration
    : type_specifier ID SEMI {
        $$ = create_declaration_node($1->data.identifier.name, $2, NULL);
        free_ast($1);
    }
    | type_specifier ID ASSIGN expression SEMI {
        $$ = create_declaration_node($1->data.identifier.name, $2, $4);
        free_ast($1);
    }
    | type_specifier ID LBRACKET RBRACKET ASSIGN LBRACE argument_list RBRACE SEMI {
        $$ = create_array_declaration_node($1->data.identifier.name, $2, NULL, $7);
        free_ast($1);
    }
    | type_specifier ID LBRACKET INT RBRACKET SEMI {
        $$ = create_array_declaration_node($1->data.identifier.name, $2, create_int_node($4), NULL);
        free_ast($1);
    }
    | LET_PTR ID ASSIGN expression SEMI {
        $$ = create_declaration_node("int*", $2, $4);
    }
    ;

type_specifier
    : LET { $$ = create_identifier_node("int"); }
    | DEC { $$ = create_identifier_node("double"); }
    | STR_TYPE { $$ = create_identifier_node("const char*"); }
    | CHR_TYPE { $$ = create_identifier_node("char"); }
    | BUL_TYPE { $$ = create_identifier_node("bool"); }
    | NUL_TYPE { $$ = create_identifier_node("void"); }
    | CLS { $$ = create_identifier_node("struct"); }
    | ENM { $$ = create_identifier_node("enum"); }
    ;

expression_statement
    : SEMI { $$ = NULL; }
    | expression SEMI { $$ = $1; }
    ;

compound_statement
    : LBRACE statement_list RBRACE { $$ = $2; }
    ;

selection_statement
    : IF_COLON expression LBRACE statement_list RBRACE {
        $$ = create_if_node($2, $4, NULL);
    }
    | IF_COLON expression LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE {
        $$ = create_if_node($2, $4, $8);
    }
    | IF_COLON expression LBRACE statement_list RBRACE ELIF_COLON expression LBRACE statement_list RBRACE {
        ASTNode *elif_node = create_if_node($7, $9, NULL);
        $$ = create_if_node($2, $4, elif_node);
    }
    ;

iteration_statement
    : WHILE_COLON expression LBRACE statement_list RBRACE {
        $$ = create_while_node($2, $4);
    }
    | DO LBRACE statement_list RBRACE WHILE_COLON expression SEMI {
        $$ = create_do_while_node($3, $6);
    }
    ;

jump_statement
    : RET expression SEMI { $$ = create_return_node($2); }
    | RET SEMI { $$ = create_return_node(NULL); }
    | BRK SEMI { $$ = create_break_node(); }
    | CNT SEMI { $$ = create_continue_node(); }
    ;

expression
    : assignment_expression { $$ = $1; }
    ;

assignment_expression
    : logical_or_expression { $$ = $1; }
    | unary_expression ASSIGN assignment_expression {
        $$ = create_binary_op_node("=", $1, $3);
    }
    ;

logical_or_expression
    : logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression {
        $$ = create_binary_op_node("||", $1, $3);
    }
    ;

logical_and_expression
    : equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression {
        $$ = create_binary_op_node("&&", $1, $3);
    }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression {
        $$ = create_binary_op_node("==", $1, $3);
    }
    | equality_expression NE relational_expression {
        $$ = create_binary_op_node("!=", $1, $3);
    }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression LT additive_expression {
        $$ = create_binary_op_node("<", $1, $3);
    }
    | relational_expression GT additive_expression {
        $$ = create_binary_op_node(">", $1, $3);
    }
    | relational_expression LE additive_expression {
        $$ = create_binary_op_node("<=", $1, $3);
    }
    | relational_expression GE additive_expression {
        $$ = create_binary_op_node(">=", $1, $3);
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression PLUS multiplicative_expression {
        $$ = create_binary_op_node("+", $1, $3);
    }
    | additive_expression MINUS multiplicative_expression {
        $$ = create_binary_op_node("-", $1, $3);
    }
    ;

multiplicative_expression
    : unary_expression { $$ = $1; }
    | multiplicative_expression MUL unary_expression {
        $$ = create_binary_op_node("*", $1, $3);
    }
    | multiplicative_expression DIV unary_expression {
        $$ = create_binary_op_node("/", $1, $3);
    }
    | multiplicative_expression MOD unary_expression {
        $$ = create_binary_op_node("%", $1, $3);
    }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
    | INC unary_expression { $$ = create_unary_op_node("++", $2); }
    | DECR unary_expression { $$ = create_unary_op_node("--", $2); }
    | NOT unary_expression { $$ = create_unary_op_node("!", $2); }
    | MINUS unary_expression { $$ = create_unary_op_node("-", $2); }
    | BITAND unary_expression { $$ = create_unary_op_node("&", $2); }
    ;

postfix_expression
    : primary_expression { $$ = $1; }
    | postfix_expression LBRACKET expression RBRACKET {
        if ($1->type == NODE_IDENTIFIER) {
            $$ = create_array_access_node($1->data.identifier.name, $3);
            free_ast($1);
        } else {
            $$ = NULL;
        }
    }
    | postfix_expression LBRACKET slice_expression RBRACKET {
        if ($1->type == NODE_IDENTIFIER) {
            $$ = create_array_slice_node($1->data.identifier.name, 
                   $3->data.slice_expr.start, $3->data.slice_expr.stop, $3->data.slice_expr.step);
            free_ast($1);
            free_ast($3);
        } else {
            $$ = NULL;
        }
    }
    | postfix_expression LPAREN RPAREN {
        if ($1->type == NODE_IDENTIFIER) {
            $$ = create_function_call_node($1->data.identifier.name, NULL);
            free_ast($1);
        } else {
            $$ = NULL;
        }
    }
    | postfix_expression LPAREN argument_list RPAREN {
        if ($1->type == NODE_IDENTIFIER) {
            $$ = create_function_call_node($1->data.identifier.name, $3);
            free_ast($1);
        } else {
            $$ = NULL;
        }
    }
    | postfix_expression INC {
        $$ = create_unary_op_node("post++", $1);
    }
    | postfix_expression DECR {
        $$ = create_unary_op_node("post--", $1);
    }
    | OUT LPAREN argument_list RPAREN {
        $$ = create_out_node($3);
    }
    | INP LPAREN argument_list RPAREN {
        $$ = create_inp_node($3);
    }
    | PRINT_SLICE LPAREN expression RPAREN {
        $$ = create_builtin_node("print_int_slice", $3);
    }
    | FREE_SLICE LPAREN expression RPAREN {
        $$ = create_builtin_node("free_int_slice", $3);
    }
    | GCD_FUNC LPAREN argument_list RPAREN {
        $$ = create_builtin_node("gcd", $3);
    }
    | ISPRIME_FUNC LPAREN expression RPAREN {
        $$ = create_builtin_node("isprime", $3);
    }
    | FACTORIAL_FUNC LPAREN expression RPAREN {
        $$ = create_builtin_node("factorial", $3);
    }
    | ISPALINDROME_FUNC LPAREN expression RPAREN {
        $$ = create_builtin_node("ispalindrome", $3);
    }
    | SUM_FUNC LPAREN argument_list RPAREN {
        $$ = create_builtin_node("sum", $3);
    }
    | MAX_FUNC LPAREN argument_list RPAREN {
        $$ = create_builtin_node("max", $3);
    }
    | MIN_FUNC LPAREN argument_list RPAREN {
        $$ = create_builtin_node("min", $3);
    }
    | AVG_FUNC LPAREN argument_list RPAREN {
        $$ = create_builtin_node("avg", $3);
    }
    | SWAP_FUNC LPAREN argument_list RPAREN {
        $$ = create_builtin_node("swap", $3);
    }
    ;

slice_expression
    : expression COLON expression COLON expression {
        $$ = create_slice_node($1, $3, $5);
    }
    | expression COLON expression {
        $$ = create_slice_node($1, $3, NULL);
    }
    | COLON expression COLON expression {
        $$ = create_slice_node(NULL, $2, $4);
    }
    | COLON expression {
        $$ = create_slice_node(NULL, $2, NULL);
    }
    | expression COLON {
        $$ = create_slice_node($1, NULL, NULL);
    }
    | COLON COLON expression {
        $$ = create_slice_node(NULL, NULL, $3);
    }
    | COLON COLON {
        $$ = create_slice_node(NULL, NULL, NULL);
    }
    ;

primary_expression
    : ID { $$ = create_identifier_node($1); free($1); }
    | INT { $$ = create_int_node($1); }
    | FLOAT { $$ = create_float_node($1); }
    | STRING { $$ = create_string_node($1); free($1); }
    | CHAR { $$ = create_char_node($1[1]); free($1); }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

argument_list
    : expression { $$ = $1; }
    | argument_list COMMA expression {
        ASTNode *last = $1;
        while (last->next) last = last->next;
        last->next = $3;
        $$ = $1;
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s near '%s'\n", yylineno, s, yytext);
}

