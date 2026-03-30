%option noyywrap yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmm_parser.tab.h"

extern FILE *token_file;

void log_token(const char *type, const char *value) {
    if (token_file) {
        fprintf(token_file, "<LINE:%d> <%s:%s>\n", yylineno, type, value);
    }
}
%}

DIGIT   [0-9]
LETTER  [A-Za-z_]
ID      {LETTER}({LETTER}|{DIGIT})*
INT     {DIGIT}+
FLOAT   {DIGIT}+"."{DIGIT}+

%%

[ \t\r\n]+          { /* Skip whitespace */ }
"//".*              { /* Skip comments */ }

    /* Keywords */
"M()"               { log_token("MAIN_FUNC", yytext); return MAIN_FUNC; }
"let"               { log_token("LET", yytext); return LET; }
"__let_ptr"         { log_token("LET_PTR", yytext); return LET_PTR; }
"dec"               { log_token("DEC", yytext); return DEC; }
"str"               { log_token("STR_TYPE", yytext); return STR_TYPE; }
"chr"               { log_token("CHR_TYPE", yytext); return CHR_TYPE; }
"bul"               { log_token("BUL_TYPE", yytext); return BUL_TYPE; }
"nul"               { log_token("NUL_TYPE", yytext); return NUL_TYPE; }
"cls"               { log_token("STRUCT", yytext); return CLS; }
"enm"               { log_token("ENUM", yytext); return ENM; }
"typ"               { log_token("TYPEDEF", yytext); return TYP; }
"con"               { log_token("CONST", yytext); return CON; }

    /* Control flow */
"if:"               { log_token("IF_COLON", yytext); return IF_COLON; }
"elif:"             { log_token("ELIF_COLON", yytext); return ELIF_COLON; }
"whl:"              { log_token("WHILE_COLON", yytext); return WHILE_COLON; }
"do"                { log_token("DO", yytext); return DO; }
"els"               { log_token("ELSE", yytext); return ELSE; }
"brk"               { log_token("BREAK", yytext); return BRK; }
"cnt"               { log_token("CONTINUE", yytext); return CNT; }
"ret"               { log_token("RETURN", yytext); return RET; }

    /* I/O */
"out"               { log_token("OUT", yytext); return OUT; }
"inp"               { log_token("INP", yytext); return INP; }
"__print_slice"     { log_token("PRINT_SLICE", yytext); return PRINT_SLICE; }
"__free_slice"      { log_token("FREE_SLICE", yytext); return FREE_SLICE; }

    /* Logical operators */
"and"               { log_token("AND", yytext); return AND; }
"or"                { log_token("OR", yytext); return OR; }
"not"               { log_token("NOT", yytext); return NOT; }

    /* Built-in functions */
"gcd"               { log_token("GCD_FUNC", yytext); return GCD_FUNC; }
"isprime"           { log_token("ISPRIME_FUNC", yytext); return ISPRIME_FUNC; }
"factorial"         { log_token("FACTORIAL_FUNC", yytext); return FACTORIAL_FUNC; }
"ispalindrome"      { log_token("ISPALINDROME_FUNC", yytext); return ISPALINDROME_FUNC; }
"sum"               { log_token("SUM_FUNC", yytext); return SUM_FUNC; }
"max"               { log_token("MAX_FUNC", yytext); return MAX_FUNC; }
"min"               { log_token("MIN_FUNC", yytext); return MIN_FUNC; }
"avg"               { log_token("AVG_FUNC", yytext); return AVG_FUNC; }
"swap"              { log_token("SWAP_FUNC", yytext); return SWAP_FUNC; }

    /* Relational operators */
">="                { log_token("GE", yytext); return GE; }
"<="                { log_token("LE", yytext); return LE; }
"=="                { log_token("EQ", yytext); return EQ; }
"!="                { log_token("NE", yytext); return NE; }

    /* Increment/Decrement */
"++"                { log_token("INC", yytext); return INC; }
"--"                { log_token("DECR", yytext); return DECR; }

    /* Arithmetic operators */
"+"                 { log_token("PLUS", yytext); return PLUS; }
"-"                 { log_token("MINUS", yytext); return MINUS; }
"*"                 { log_token("MUL", yytext); return MUL; }
"/"                 { log_token("DIV", yytext); return DIV; }
"%"                 { log_token("MOD", yytext); return MOD; }
"**"                { log_token("POW_OP", yytext); return POW_OP; }

    /* Assignment */
"="                 { log_token("ASSIGN", yytext); return ASSIGN; }

    /* Comparison */
"<"                 { log_token("LT", yytext); return LT; }
">"                 { log_token("GT", yytext); return GT; }

    /* Bitwise operators */
"&"                 { log_token("BITAND", yytext); return BITAND; }
"|"                 { log_token("BITOR", yytext); return BITOR; }
"^"                 { log_token("BITXOR", yytext); return BITXOR; }
"~"                 { log_token("BITNOT", yytext); return BITNOT; }
"<<"                { log_token("LSHIFT", yytext); return LSHIFT; }
">>"                { log_token("RSHIFT", yytext); return RSHIFT; }

    /* Delimiters */
"("                 { log_token("LPAREN", yytext); return LPAREN; }
")"                 { log_token("RPAREN", yytext); return RPAREN; }
"{"                 { log_token("LBRACE", yytext); return LBRACE; }
"}"                 { log_token("RBRACE", yytext); return RBRACE; }
";"                 { log_token("SEMI", yytext); return SEMI; }
","                 { log_token("COMMA", yytext); return COMMA; }
":"                 { log_token("COLON", yytext); return COLON; }
"["                 { log_token("LBRACKET", yytext); return LBRACKET; }
"]"                 { log_token("RBRACKET", yytext); return RBRACKET; }
"."                 { log_token("DOT", yytext); return DOT; }

    /* Literals */
\"[^"\n]*\"         { 
                      log_token("STRING", yytext); 
                      yylval.sval = strdup(yytext); 
                      return STRING; 
                    }
\'[^'\n]\'          { 
                      log_token("CHAR", yytext); 
                      yylval.sval = strdup(yytext); 
                      return CHAR; 
                    }

{FLOAT}             { 
                      log_token("FLOAT", yytext); 
                      yylval.fval = atof(yytext); 
                      return FLOAT; 
                    }
{INT}               { 
                      log_token("INT", yytext); 
                      yylval.ival = atoi(yytext); 
                      return INT; 
                    }
{ID}                { 
                      log_token("ID", yytext); 
                      yylval.sval = strdup(yytext); 
                      return ID; 
                    }

.                   { 
                      log_token("UNKNOWN", yytext); 
                      fprintf(stderr, "Unknown character: %s at line %d\n", yytext, yylineno);
                    }

%%
