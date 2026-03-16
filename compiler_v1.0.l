%option noyywrap yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static FILE *tokout = NULL;
static FILE *cout = NULL;

static void emit(const char *name) 
{
    fprintf(tokout, "<LINE:%d> <%s>\n", yylineno, name);
}
static void emitv(const char *name, const char *val) 
{
    fprintf(tokout,"<LINE:%d> <%s:%s>\n", yylineno, name, val);
}
static void cwrite(const char *s) 
{
    fputs(s, cout);
}
static void ctext(void) 
{
    fputs(yytext, cout);
}

int need_close_paren = 0;
int skip_next_brace = 0;
int in_main_body = 0;
int brace_depth = 0;

%}

DIGIT   [0-9]
LETTER  [A-Za-z_]
ID      {LETTER}({LETTER}|{DIGIT})*
INT     {DIGIT}+
FLOAT   {DIGIT}+"."{DIGIT}+

%%

[ \t\r]+            { ctext(); }
"\n"                { ctext(); }

"//".*              { ctext(); }

\"[^"\n]*\"         { emitv("STRING", yytext); cwrite(yytext); }
\'[^'\n]*\'         { emitv("CHAR", yytext); cwrite(yytext); }

"M()"               { 
                      emit("MAIN_FUNC"); 
                      skip_next_brace = 1;
                      in_main_body = 1;
                      brace_depth = 0;
                    }

"let"               { emit("LET"); cwrite("int "); }
"dec"               { emit("DEC"); cwrite("double "); }
"str"               { emit("STR_TYPE"); cwrite("const char* "); }
"chr"               { emit("CHAR_TYPE"); cwrite("char "); }
"bul"               { emit("BOOL_TYPE"); cwrite("bool "); }
"nul"               { emit("VOID_TYPE"); cwrite("void "); }
"cls"               { emit("STRUCT"); cwrite("struct "); }
"enm"               { emit("ENUM"); cwrite("enum "); }
"typ"               { emit("TYPEDEF"); cwrite("typedef "); }
"con"               { emit("CONST"); cwrite("const "); }

"if:"               { emit("IF_COLON"); cwrite("if ("); need_close_paren = 1; }
"elif:"             { emit("ELIF_COLON"); cwrite("else if ("); need_close_paren = 1; }
"whl:"              { emit("WHILE_COLON"); cwrite("while ("); need_close_paren = 1; }
"do"                { emit("DO"); cwrite("do"); }
"els"               { emit("ELSE"); cwrite("else"); }
"brk"               { emit("BREAK"); cwrite("break"); }
"cnt"               { emit("CONTINUE"); cwrite("continue"); }

"ret"               { emit("RETURN"); cwrite("return"); }

"out"               { emit("OUT"); cwrite("printf"); }
"inp"               { emit("INP"); cwrite("scanf"); }

"and"               { emit("AND"); cwrite("&&"); }
"or"                { emit("OR"); cwrite("||"); }
"not"               { emit("NOT"); cwrite("!"); }

{ID}"**"{INT}        {
                      char base[128], exp[128];
                      sscanf(yytext, "%[^*]**%s", base, exp);
                      emitv("POW_EXPR", yytext);
                      cwrite("(int)pow(");
                      cwrite(base);
                      cwrite(", ");
                      cwrite(exp);
                      cwrite(")");
                    }

{INT}"**"{ID}        {
                      char base[128], exp[128];
                      sscanf(yytext, "%[^*]**%s", base, exp);
                      emitv("POW_EXPR", yytext);
                      cwrite("(int)pow(");
                      cwrite(base);
                      cwrite(", ");
                      cwrite(exp);
                      cwrite(")");
                    }

{ID}"**"{ID}        {
                      char base[128], exp[128];
                      sscanf(yytext, "%[^*]**%s", base, exp);
                      emitv("POW_EXPR", yytext);
                      cwrite("(int)pow(");
                      cwrite(base);
                      cwrite(", ");
                      cwrite(exp);
                      cwrite(")");
                    }

{INT}"**"{INT}      {
                      char base[128], exp[128];
                      sscanf(yytext, "%[^*]**%s", base, exp);
                      emitv("POW_EXPR", yytext);
                      cwrite("(int)pow(");
                      cwrite(base);
                      cwrite(", ");
                      cwrite(exp);
                      cwrite(")");
                    }

"**"                { 
                      emit("POW_OP"); 
                      cwrite("**");
                    }

"gcd"               { emit("GCD_FUNC"); cwrite("gcd"); }
"isprime"           { emit("ISPRIME_FUNC"); cwrite("isprime"); }
"factorial"         { emit("FACTORIAL_FUNC"); cwrite("factorial"); }
"ispalindrome"      { emit("ISPALINDROME_FUNC"); cwrite("ispalindrome"); }
"sum"               { emit("SUM_FUNC"); cwrite("sum"); }
"max"               { emit("MAX_FUNC"); cwrite("max"); }
"min"               { emit("MIN_FUNC"); cwrite("min"); }
"avg"               { emit("AVG_FUNC"); cwrite("avg"); }
"swap"              { emit("SWAP_FUNC"); cwrite("swap"); }

">="                { emit("GE"); ctext(); }
"<="                { emit("LE"); ctext(); }
"=="                { emit("EQ"); ctext(); }
"!="                { emit("NE"); ctext(); }
"++"                { emit("INC"); ctext(); }
"--"                { emit("DECR"); ctext(); }
"+"                 { emit("PLUS"); ctext(); }
"-"                 { emit("MINUS"); ctext(); }
"*"                 { emit("MUL"); ctext(); }
"/"                 { emit("DIV"); ctext(); }
"%"                 { emit("MOD"); ctext(); }
"="                 { emit("ASSIGN"); ctext(); }
"<"                 { emit("LT"); ctext(); }
">"                 { emit("GT"); ctext(); }
"&"                 { emit("BITAND"); ctext(); }
"|"                 { emit("BITOR"); ctext(); }
"^"                 { emit("BITXOR"); ctext(); }
"~"                 { emit("BITNOT"); ctext(); }
"<<"                { emit("LSHIFT"); ctext(); }
">>"                { emit("RSHIFT"); ctext(); }

"("                 { 
                      emit("LPAREN"); 
                      cwrite("("); 
                    }
")"                 { 
                      emit("RPAREN"); 
                      cwrite(")"); 
                      need_close_paren = 0;
                    }
"{"                 { 
                      emit("LBRACE"); 
                      if (skip_next_brace) {
                          skip_next_brace = 0;
                      } else {
                          if (need_close_paren) {
                              cwrite(") {"); 
                              need_close_paren = 0;
                          } else {
                              cwrite("{");
                          }
                          if (in_main_body) brace_depth++;
                      }
                    }
"}"                 { 
                      emit("RBRACE"); 
                      if (in_main_body && brace_depth == 0) {
                          in_main_body = 0;
                      } else {
                          cwrite("}");
                          if (in_main_body && brace_depth > 0) brace_depth--;
                      }
                    }
";"                 { 
                      emit("SEMI"); 
                      if (need_close_paren) {
                          cwrite(");");
                          need_close_paren = 0;
                      } else {
                          cwrite(";");
                      }
                    }
","                 { emit("COMMA"); cwrite(", "); }
":"                 { emit("COLON"); ctext(); }
"["                 { emit("LBRACKET"); cwrite("["); }
"]"                 { emit("RBRACKET"); cwrite("]"); }
"."                 { emit("DOT"); ctext(); }

{FLOAT}             { emitv("FLOAT", yytext); ctext(); }
{INT}               { emitv("INT", yytext); ctext(); }
{ID}                { emitv("ID", yytext); ctext(); }

.                   { emitv("UNKNOWN", yytext); ctext(); }

<<EOF>>             { return 0; }

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.cmm>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) { perror("open input"); return 1; }
    yyin = in;

    cout = fopen("out.c", "w");
    if (!cout) { perror("open out.c"); fclose(in); return 1; }

    tokout = fopen("tokens.txt", "w");
    if (!tokout) { perror("open tokens"); fclose(cout); fclose(in); return 1; }


    fputs("#include <stdio.h>\n", cout);
    fputs("#include <stdbool.h>\n", cout);
    fputs("#include <math.h>\n", cout);
    fputs("#include <string.h>\n\n", cout);
    
   
    fputs("// C-- built-in functions\n", cout);
    fputs("int gcd(int a, int b);\n", cout);
    fputs("bool isprime(int n);\n", cout);
    fputs("long long factorial(int n);\n", cout);
    fputs("bool ispalindrome(const char* str);\n", cout);
    fputs("int sum(int arr[], int size);\n", cout);
    fputs("int max(int arr[], int size);\n", cout);
    fputs("int min(int arr[], int size);\n", cout);
    fputs("double avg(int arr[], int size);\n", cout);
    fputs("void swap(int* a, int* b);\n\n", cout);
    
    
    fputs("/* Built-in Function Implementations */\n\n", cout);
    
    fputs("int gcd(int a, int b) {\n", cout);
    fputs("    while (b != 0) {\n", cout);
    fputs("        int temp = b;\n", cout);
    fputs("        b = a % b;\n", cout);
    fputs("        a = temp;\n", cout);
    fputs("    }\n", cout);
    fputs("    return a;\n", cout);
    fputs("}\n\n", cout);
    
    fputs("bool isprime(int n) {\n", cout);
    fputs("    if (n <= 1) return false;\n", cout);
    fputs("    if (n <= 3) return true;\n", cout);
    fputs("    if (n % 2 == 0 || n % 3 == 0) return false;\n", cout);
    fputs("    for (int i = 5; i * i <= n; i += 6) {\n", cout);
    fputs("        if (n % i == 0 || n % (i + 2) == 0) return false;\n", cout);
    fputs("    }\n", cout);
    fputs("    return true;\n", cout);
    fputs("}\n\n", cout);
    
    fputs("long long factorial(int n) {\n", cout);
    fputs("    long long result = 1;\n", cout);
    fputs("    for (int i = 2; i <= n; i++) result *= i;\n", cout);
    fputs("    return result;\n", cout);
    fputs("}\n\n", cout);
    
    fputs("bool ispalindrome(const char* str) {\n", cout);
    fputs("    int len = strlen(str);\n", cout);
    fputs("    for (int i = 0; i < len / 2; i++)\n", cout);
    fputs("        if (str[i] != str[len - i - 1]) return false;\n", cout);
    fputs("    return true;\n", cout);
    fputs("}\n\n", cout);
    
    fputs("int sum(int arr[], int size) {\n", cout);
    fputs("    int total = 0;\n", cout);
    fputs("    for (int i = 0; i < size; i++) total += arr[i];\n", cout);
    fputs("    return total;\n", cout);
    fputs("}\n\n", cout);
    
    fputs("int max(int arr[], int size) {\n", cout);
    fputs("    int m = arr[0];\n", cout);
    fputs("    for (int i = 1; i < size; i++)\n", cout);
    fputs("        if (arr[i] > m) m = arr[i];\n", cout);
    fputs("    return m;\n", cout);
    fputs("}\n\n", cout);
    
    fputs("int min(int arr[], int size) {\n", cout);
    fputs("    int m = arr[0];\n", cout);
    fputs("    for (int i = 1; i < size; i++)\n", cout);
    fputs("        if (arr[i] < m) m = arr[i];\n", cout);
    fputs("    return m;\n", cout);
    fputs("}\n\n", cout);
    
    fputs("double avg(int arr[], int size) {\n", cout);
    fputs("    return size ? (double)sum(arr, size) / size : 0.0;\n", cout);
    fputs("}\n\n", cout);
    
    fputs("void swap(int* a, int* b) {\n", cout);
    fputs("    int t = *a;\n", cout);
    fputs("    *a = *b;\n", cout);
    fputs("    *b = t;\n", cout);
    fputs("}\n\n", cout);
    
    // Main function
    fputs("int main() {\n", cout);
    
    yylex();

    fputs("}\n", cout);
    
    fclose(tokout);
    fclose(cout);
    fclose(in);
    
    printf("Compilation successful! Output: out.c\n");
    return 0;
}
