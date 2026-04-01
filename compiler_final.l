%option noyywrap yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ast.h"

static FILE *tokout = NULL;
static FILE *cout = NULL;
static int slice_counter = 0;
static char global_array_content[500] = "";
static int global_arr_length = 0;

static void emit(const char *name) {
    fprintf(tokout, "<LINE:%d> <%s>\n", yylineno, name);
}
static void emitv(const char *name, const char *val) {
    fprintf(tokout, "<LINE:%d> <%s:%s>\n", yylineno, name, val);
}
static void cwrite(const char *s) {
    fputs(s, cout);
}
static void ctext(void) {
    fputs(yytext, cout);
}

int need_close_paren = 0;
int skip_next_brace = 0;
int in_main_body = 0;
int brace_depth = 0;

// Function to handle chained comparisons
char* expand_chained_comparison(const char *expr) {
    static char result[1024];
    char operators[10][3];
    int op_positions[10];
    int comp_count = 0;
    
    for (int i = 0; expr[i]; i++) {
        if (strncmp(&expr[i], "<=", 2) == 0) {
            strcpy(operators[comp_count], "<=");
            op_positions[comp_count] = i;
            comp_count++;
            i++;
            continue;
        }
        if (strncmp(&expr[i], ">=", 2) == 0) {
            strcpy(operators[comp_count], ">=");
            op_positions[comp_count] = i;
            comp_count++;
            i++;
            continue;
        }
        if (strncmp(&expr[i], "==", 2) == 0) {
            strcpy(operators[comp_count], "==");
            op_positions[comp_count] = i;
            comp_count++;
            i++;
            continue;
        }
        if (strncmp(&expr[i], "!=", 2) == 0) {
            strcpy(operators[comp_count], "!=");
            op_positions[comp_count] = i;
            comp_count++;
            i++;
            continue;
        }
        if (expr[i] == '<') {
            strcpy(operators[comp_count], "<");
            op_positions[comp_count] = i;
            comp_count++;
            continue;
        }
        if (expr[i] == '>') {
            strcpy(operators[comp_count], ">");
            op_positions[comp_count] = i;
            comp_count++;
            continue;
        }
    }
    
    if (comp_count <= 1) {
        strcpy(result, expr);
        return result;
    }
    
    char operands[10][100];
    int op_idx = 0;
    
    int idx = 0;
    for (int i = 0; i < op_positions[0]; i++) {
        if (expr[i] != ' ') {
            operands[op_idx][idx++] = expr[i];
        }
    }
    operands[op_idx][idx] = '\0';
    op_idx++;
    
    for (int i = 0; i < comp_count - 1; i++) {
        idx = 0;
        int start = op_positions[i] + strlen(operators[i]);
        int end = op_positions[i + 1];
        for (int j = start; j < end; j++) {
            if (expr[j] != ' ') {
                operands[op_idx][idx++] = expr[j];
            }
        }
        operands[op_idx][idx] = '\0';
        op_idx++;
    }
    
    idx = 0;
    int start = op_positions[comp_count - 1] + strlen(operators[comp_count - 1]);
    for (int i = start; expr[i]; i++) {
        if (expr[i] != ' ') {
            operands[op_idx][idx++] = expr[i];
        }
    }
    operands[op_idx][idx] = '\0';
    
    result[0] = '\0';
    for (int i = 0; i < comp_count; i++) {
        if (i > 0) strcat(result, " && ");
        strcat(result, "(");
        strcat(result, operands[i]);
        strcat(result, " ");
        strcat(result, operators[i]);
        strcat(result, " ");
        strcat(result, operands[i + 1]);
        strcat(result, ")");
    }
    
    return result;
}

void extract_array(const char *input_file, char *array_str, int *length) {
    FILE *in = fopen(input_file, "r");
    if (!in) return;
    
    char line[1024];
    *length = 0;
    
    while (fgets(line, sizeof(line), in)) {
        char *ptr = line;
        while (*ptr == ' ' || *ptr == '\t') ptr++;
        
        char *brace = strchr(ptr, '{');
        if (brace) {
            char *bracket = strchr(ptr, '[');
            if (bracket && bracket < brace) {
                char *end_brace = strchr(brace, '}');
                if (end_brace) {
                    int count = 0;
                    int in_number = 0;
                    for (char *p = brace + 1; p < end_brace; p++) {
                        if ((isdigit(*p) || (*p == '-' && !in_number)) && !in_number) {
                            count++;
                            in_number = 1;
                        } else if (!isdigit(*p) && *p != '-') {
                            in_number = 0;
                        }
                    }
                    if (count > 0) {
                        *length = count;
                        int idx = 0;
                        for (char *p = brace + 1; p < end_brace && idx < 499; p++) {
                            array_str[idx++] = *p;
                        }
                        array_str[idx] = '\0';
                        fclose(in);
                        return;
                    }
                }
            }
        }
    }
    fclose(in);
}

void parse_slice_expression(const char *slice_expr, char *start_code, char *stop_code, char *step_code, int arr_length) {
    start_code[0] = '\0';
    stop_code[0] = '\0';
    step_code[0] = '\0';
    
    char start_expr[50] = "";
    char stop_expr[50] = "";
    char step_expr[50] = "";
    
    int part = 0;
    int i = 0;
    char *dest = start_expr;
    
    for (const char *p = slice_expr; *p; p++) {
        if (*p == ':') {
            dest[i] = '\0';
            part++;
            if (part == 1) {
                dest = stop_expr;
                i = 0;
            } else if (part == 2) {
                dest = step_expr;
                i = 0;
            }
        } else {
            dest[i++] = *p;
        }
    }
    dest[i] = '\0';
    
    int colon_count = 0;
    for (const char *p = slice_expr; *p; p++) {
        if (*p == ':') colon_count++;
    }
    
    if (colon_count == 2) {
        if (strlen(start_expr) == 0) {
            if (strlen(step_expr) > 0 && atoi(step_expr) < 0) {
                strcpy(start_code, "arr_length - 1");
            } else {
                strcpy(start_code, "0");
            }
        } else {
            strcpy(start_code, start_expr);
        }
        
        if (strlen(stop_expr) == 0) {
            if (strlen(step_expr) > 0 && atoi(step_expr) < 0) {
                strcpy(stop_code, "-1");
            } else {
                strcpy(stop_code, "arr_length");
            }
        } else {
            strcpy(stop_code, stop_expr);
        }
        
        if (strlen(step_expr) == 0) {
            strcpy(step_code, "1");
        } else {
            strcpy(step_code, step_expr);
        }
    } else if (colon_count == 1) {
        if (strlen(start_expr) == 0) {
            strcpy(start_code, "0");
        } else {
            strcpy(start_code, start_expr);
        }
        
        if (strlen(stop_expr) == 0) {
            strcpy(stop_code, "arr_length");
        } else {
            strcpy(stop_code, stop_expr);
        }
        
        strcpy(step_code, "1");
    } else if (colon_count == 0) {
        strcpy(start_code, slice_expr);
        char temp[50];
        sprintf(temp, "(%s) + 1", slice_expr);
        strcpy(stop_code, temp);
        strcpy(step_code, "1");
    }
}

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
"__let_ptr"         { emit("LET_PTR"); cwrite("int* "); }
"dec"               { emit("DEC"); cwrite("double "); }
"str"               { emit("STR_TYPE"); cwrite("const char* "); }
"chr"               { emit("CHAR_TYPE"); cwrite("char "); }
"bul"               { emit("BOOL_TYPE"); cwrite("bool "); }
"nul"               { emit("VOID_TYPE"); cwrite("void "); }
"cls"               { emit("STRUCT"); cwrite("struct "); }
"enm"               { emit("ENUM"); cwrite("enum "); }
"typ"               { emit("TYPEDEF"); cwrite("typedef "); }
"con"               { emit("CONST"); cwrite("const "); }

"for"               { emit("FOR"); cwrite("for "); }
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
"__print_slice"     { emit("PRINT_SLICE"); cwrite("print_int_slice"); }
"__free_slice"      { emit("FREE_SLICE"); cwrite("free_int_slice"); }

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

void write_slice_functions(FILE *out) {
    fprintf(out, "int* int_slice_step(int* arr, int start, int stop, int step, int length) {\n");
    fprintf(out, "    if (step < 0 && stop == -1) {\n");
    fprintf(out, "        if (start < 0) start = length + start;\n");
    fprintf(out, "        if (start < 0) start = -1;\n");
    fprintf(out, "        else if (start >= length) start = length - 1;\n");
    fprintf(out, "        int slice_length = (start + 1) / (-step);\n");
    fprintf(out, "        if ((start + 1) %% (-step) != 0) slice_length++;\n");
    fprintf(out, "        if (slice_length <= 0) {\n");
    fprintf(out, "            int* result = (int*)malloc(sizeof(int));\n");
    fprintf(out, "            if (result) result[0] = 0;\n");
    fprintf(out, "            return result;\n");
    fprintf(out, "        }\n");
    fprintf(out, "        int* result = (int*)malloc((slice_length + 1) * sizeof(int));\n");
    fprintf(out, "        if (!result) return NULL;\n");
    fprintf(out, "        result[0] = slice_length;\n");
    fprintf(out, "        for (int i = 0; i < slice_length; i++) {\n");
    fprintf(out, "            result[i + 1] = arr[start + i * step];\n");
    fprintf(out, "        }\n");
    fprintf(out, "        return result;\n");
    fprintf(out, "    }\n");
    fprintf(out, "    if (step == 0) { printf(\"Error: Step cannot be zero\\n\"); return NULL; }\n");
    fprintf(out, "    if (start < 0) start = length + start;\n");
    fprintf(out, "    if (stop < 0) stop = length + stop;\n");
    fprintf(out, "    if (step > 0) {\n");
    fprintf(out, "        if (start < 0) start = 0;\n");
    fprintf(out, "        else if (start > length) start = length;\n");
    fprintf(out, "        if (stop < 0) stop = 0;\n");
    fprintf(out, "        else if (stop > length) stop = length;\n");
    fprintf(out, "    } else {\n");
    fprintf(out, "        if (start < 0) start = -1;\n");
    fprintf(out, "        else if (start >= length) start = length - 1;\n");
    fprintf(out, "        if (stop < 0) stop = -1;\n");
    fprintf(out, "        else if (stop > length) stop = length;\n");
    fprintf(out, "    }\n");
    fprintf(out, "    if ((step > 0 && start >= stop) || (step < 0 && start <= stop)) {\n");
    fprintf(out, "        int* result = (int*)malloc(sizeof(int));\n");
    fprintf(out, "        if (result) result[0] = 0;\n");
    fprintf(out, "        return result;\n");
    fprintf(out, "    }\n");
    fprintf(out, "    int slice_length;\n");
    fprintf(out, "    if (step > 0) {\n");
    fprintf(out, "        slice_length = (stop - start + step - 1) / step;\n");
    fprintf(out, "    } else {\n");
    fprintf(out, "        slice_length = (start - stop - 1) / (-step) + 1;\n");
    fprintf(out, "    }\n");
    fprintf(out, "    if (slice_length <= 0) {\n");
    fprintf(out, "        int* result = (int*)malloc(sizeof(int));\n");
    fprintf(out, "        if (result) result[0] = 0;\n");
    fprintf(out, "        return result;\n");
    fprintf(out, "    }\n");
    fprintf(out, "    int* result = (int*)malloc((slice_length + 1) * sizeof(int));\n");
    fprintf(out, "    if (!result) return NULL;\n");
    fprintf(out, "    result[0] = slice_length;\n");
    fprintf(out, "    for (int i = 0; i < slice_length; i++) {\n");
    fprintf(out, "        result[i + 1] = arr[start + i * step];\n");
    fprintf(out, "    }\n");
    fprintf(out, "    return result;\n");
    fprintf(out, "}\n\n");
    
    fprintf(out, "void print_int_slice(int* slice) {\n");
    fprintf(out, "    if (!slice) { printf(\"[NULL]\\n\"); return; }\n");
    fprintf(out, "    if (slice[0] == 0) { printf(\"[]\\n\"); return; }\n");
    fprintf(out, "    printf(\"[\");\n");
    fprintf(out, "    for (int i = 1; i <= slice[0]; i++) {\n");
    fprintf(out, "        printf(\"%%d\", slice[i]);\n");
    fprintf(out, "        if (i < slice[0]) printf(\", \");\n");
    fprintf(out, "    }\n");
    fprintf(out, "    printf(\"]\\n\");\n");
    fprintf(out, "}\n\n");
    
    fprintf(out, "void free_int_slice(int* slice) {\n");
    fprintf(out, "    if (slice) free(slice);\n");
    fprintf(out, "}\n\n");
}

void preprocess_slicing_and_chained_comparisons(const char *input_file, const char *temp_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(temp_file, "w");
    
    if (!in) {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", input_file);
        if (out) fclose(out);
        return;
    }
    if (!out) {
        fprintf(stderr, "Error: Cannot create temporary file '%s'\n", temp_file);
        fclose(in);
        return;
    }
    
    extract_array(input_file, global_array_content, &global_arr_length);
    
    char line[2048];
    int local_slice_counter = 0;
    
    while (fgets(line, sizeof(line), in)) {
        char *original_line = strdup(line);
        char *trimmed = original_line;
        while (*trimmed == ' ' || *trimmed == '\t') trimmed++;
        
        if (strlen(trimmed) == 0) {
            fputs(original_line, out);
            free(original_line);
            continue;
        }
        
        char *power_pos = strstr(original_line, "**");
        if (power_pos) {
            char *paren_open = NULL;
            char *p = power_pos - 1;
            while (p > original_line && (*p == ' ' || *p == '\t')) p--;
            if (*p == ')') {
                int paren_count = 1;
                char *paren_open_pos = p;
                while (paren_open_pos > original_line && paren_count > 0) {
                    paren_open_pos--;
                    if (*paren_open_pos == ')') paren_count++;
                    if (*paren_open_pos == '(') paren_count--;
                }
                if (*paren_open_pos == '(' && paren_count == 0) {
                    paren_open = paren_open_pos;
                }
            }
            
            if (paren_open) {
                char *exp_start = power_pos + 2;
                while (*exp_start == ' ' || *exp_start == '\t') exp_start++;
                char *exp_end = exp_start;
                while (*exp_end && *exp_end != ' ' && *exp_end != '\t' && *exp_end != ';' && *exp_end != '\n' && *exp_end != ')') exp_end++;
                
                char pow_expr[512];
                int base_len = power_pos - paren_open;
                int exp_len = exp_end - exp_start;
                snprintf(pow_expr, sizeof(pow_expr), "(int)pow(%.*s, %.*s)", 
                         base_len, paren_open, exp_len, exp_start);
                
                char new_line[2048];
                int prefix_len = paren_open - original_line;
                int suffix_len = strlen(exp_end);
                snprintf(new_line, sizeof(new_line), "%.*s%s%s", 
                         prefix_len, original_line, pow_expr, exp_end);
                free(original_line);
                original_line = strdup(new_line);
                trimmed = original_line;
                while (*trimmed == ' ' || *trimmed == '\t') trimmed++;
            }
        }
        
        int in_string = 0;
        int has_slice_in_string = 0;
        for (char *p = original_line; *p; p++) {
            if (*p == '"' && (p == original_line || *(p-1) != '\\')) {
                in_string = !in_string;
            }
            if (in_string && *p == '[') {
                char *colon = strchr(p, ':');
                if (colon && colon < strchr(p, '"')) {
                    has_slice_in_string = 1;
                    break;
                }
            }
        }
        
        if (has_slice_in_string) {
            fputs(original_line, out);
            free(original_line);
            continue;
        }
        
        if ((strncmp(trimmed, "if:", 3) == 0 || 
             strncmp(trimmed, "elif:", 5) == 0 || 
             strncmp(trimmed, "whl:", 4) == 0)) {
            
            char *colon = strchr(trimmed, ':');
            if (colon) {
                char *brace = strchr(colon, '{');
                if (brace) {
                    char condition[512];
                    int idx = 0;
                    for (char *p = colon + 1; p < brace && idx < 511; p++) {
                        condition[idx++] = *p;
                    }
                    condition[idx] = '\0';
                    
                    char *start = condition;
                    while (*start == ' ' || *start == '\t') start++;
                    char *end = start + strlen(start) - 1;
                    while (end > start && (*end == ' ' || *end == '\t')) end--;
                    *(end + 1) = '\0';
                    
                    int has_chained = 0;
                    int op_count = 0;
                    for (int i = 0; start[i]; i++) {
                        if ((start[i] == '<' || start[i] == '>' || start[i] == '=' || start[i] == '!') && 
                            !(i > 0 && (start[i-1] == '<' || start[i-1] == '>' || start[i-1] == '=' || start[i-1] == '!'))) {
                            op_count++;
                            if (op_count >= 2) {
                                has_chained = 1;
                                break;
                            }
                        }
                    }
                    
                    char *expanded;
                    if (has_chained) {
                        expanded = expand_chained_comparison(start);
                    } else {
                        expanded = (char*)start;
                    }
                    
                    if (strncmp(trimmed, "if:", 3) == 0) {
                        fprintf(out, "if (%s) {\n", expanded);
                    } else if (strncmp(trimmed, "elif:", 5) == 0) {
                        fprintf(out, "else if (%s) {\n", expanded);
                    } else if (strncmp(trimmed, "whl:", 4) == 0) {
                        fprintf(out, "while (%s) {\n", expanded);
                    }
                    free(original_line);
                    continue;
                }
            }
        }
        
        if (strncmp(trimmed, "out(", 4) == 0) {
            char *bracket_start = strchr(trimmed, '[');
            if (bracket_start) {
                char *bracket_end = strchr(bracket_start, ']');
                if (bracket_end) {
                    int has_colon = 0;
                    for (char *p = bracket_start + 1; p < bracket_end; p++) {
                        if (*p == ':') {
                            has_colon = 1;
                            break;
                        }
                    }
                    
                    if (has_colon) {
                        char array_name[100];
                        int idx = 0;
                        char *p = bracket_start - 1;
                        while (p > trimmed && (*p == ' ' || *p == '\t')) p--;
                        while (p > trimmed && (isalnum(*p) || *p == '_')) p--;
                        p++;
                        
                        while (p < bracket_start && *p != ' ' && *p != '\t' && *p != '(' && *p != ')' && idx < 99) {
                            array_name[idx++] = *p++;
                        }
                        array_name[idx] = '\0';
                        
                        char slice_expr[200];
                        idx = 0;
                        for (p = bracket_start + 1; p < bracket_end; p++) {
                            slice_expr[idx++] = *p;
                        }
                        slice_expr[idx] = '\0';
                        
                        char start_code[50], stop_code[50], step_code[50];
                        parse_slice_expression(slice_expr, start_code, stop_code, step_code, global_arr_length);
                        
                        fprintf(out, "    int* __slice_%d_ptr = __internal_slice(%s, %s, %s, %s);\n",
                                local_slice_counter, array_name, start_code, stop_code, step_code);
                        fprintf(out, "    print_int_slice(__slice_%d_ptr);\n", local_slice_counter);
                        fprintf(out, "    free_int_slice(__slice_%d_ptr);\n", local_slice_counter);
                        local_slice_counter++;
                        free(original_line);
                        continue;
                    }
                }
            }
        }
        
        if (strncmp(trimmed, "let ", 4) == 0 && strstr(trimmed, "=") && strstr(trimmed, "[")) {
            char *eq = strchr(trimmed, '=');
            if (eq) {
                char *bracket_start = strchr(eq, '[');
                if (bracket_start) {
                    char *bracket_end = strchr(bracket_start, ']');
                    if (bracket_end) {
                        int has_colon = 0;
                        for (char *p = bracket_start + 1; p < bracket_end; p++) {
                            if (*p == ':') {
                                has_colon = 1;
                                break;
                            }
                        }
                        
                        if (has_colon) {
                            char var_name[100];
                            int idx = 0;
                            char *p = trimmed + 4;
                            while (p < eq && *p != ' ' && *p != '\t') {
                                var_name[idx++] = *p++;
                            }
                            var_name[idx] = '\0';
                            
                            while (idx > 0 && (var_name[idx-1] == ' ' || var_name[idx-1] == '\t')) {
                                var_name[--idx] = '\0';
                            }
                            
                            char array_name[100];
                            idx = 0;
                            p = bracket_start - 1;
                            while (p > eq && (*p == ' ' || *p == '\t')) p--;
                            while (p > eq && (isalnum(*p) || *p == '_')) p--;
                            p++;
                            
                            while (p < bracket_start && *p != ' ' && *p != '\t' && idx < 99) {
                                array_name[idx++] = *p++;
                            }
                            array_name[idx] = '\0';
                            
                            char slice_expr[200];
                            idx = 0;
                            for (p = bracket_start + 1; p < bracket_end; p++) {
                                slice_expr[idx++] = *p;
                            }
                            slice_expr[idx] = '\0';
                            
                            char start_code[50], stop_code[50], step_code[50];
                            parse_slice_expression(slice_expr, start_code, stop_code, step_code, global_arr_length);
                            
                            fprintf(out, "    int* %s = __internal_slice(%s, %s, %s, %s);\n",
                                    var_name, array_name, start_code, stop_code, step_code);
                            free(original_line);
                            continue;
                        }
                    }
                }
            }
        }
        
        if (strncmp(trimmed, "out(", 4) == 0) {
            char *content = trimmed + 4;
            char *close = strstr(content, ");");
            if (close) {
                *close = '\0';
                char *start = content;
                while (*start == ' ' || *start == '\t') start++;
                
                if (!strchr(start, '"') && !strchr(start, '%')) {
                    fprintf(out, "    print_int_slice(%s);\n", start);
                } else {
                    fprintf(out, "    printf(%s);\n", start);
                }
                free(original_line);
                continue;
            }
        }
        
        fputs(original_line, out);
        free(original_line);
    }
    
    fclose(in);
    fclose(out);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.cmm>\n", argv[0]);
        return 1;
    }

    const char *temp_file = "temp_preprocessed.cmm";
    preprocess_slicing_and_chained_comparisons(argv[1], temp_file);

    FILE *in = fopen(temp_file, "r");
    if (!in) { perror("open preprocessed"); return 1; }
    yyin = in;

    cout = fopen("out.c", "w");
    if (!cout) { perror("open out.c"); fclose(in); return 1; }

    tokout = fopen("tokens.txt", "w");
    if (!tokout) { perror("open tokens"); fclose(cout); fclose(in); return 1; }

    fputs("#include <stdio.h>\n", cout);
    fputs("#include <stdbool.h>\n", cout);
    fputs("#include <math.h>\n", cout);
    fputs("#include <string.h>\n", cout);
    fputs("#include <stdlib.h>\n\n", cout);
    
    fputs("// C-- built-in functions\n", cout);
    fputs("int gcd(int a, int b);\n", cout);
    fputs("bool isprime(int n);\n", cout);
    fputs("long long factorial(int n);\n", cout);
    fputs("bool ispalindrome(const char* str);\n", cout);
    fputs("int sum(int arr[], int size);\n", cout);
    fputs("int max(int arr[], int size);\n", cout);
    fputs("int min(int arr[], int size);\n", cout);
    fputs("double avg(int arr[], int size);\n", cout);
    fputs("void swap(int* a, int* b);\n", cout);
    fputs("int* int_slice_step(int* arr, int start, int stop, int step, int length);\n", cout);
    fputs("void print_int_slice(int* slice);\n", cout);
    fputs("void free_int_slice(int* slice);\n", cout);
    fputs("#define __internal_slice(a,start,stop,step) int_slice_step(a,start,stop,step,sizeof(a)/sizeof(a[0]))\n\n", cout);
    
    fputs("/* Built-in Function Implementations */\n\n", cout);
    
    fputs("int gcd(int a, int b) {\n", cout);
    fputs("    while (b != 0) { int temp = b; b = a % b; a = temp; }\n", cout);
    fputs("    return a;\n}\n\n", cout);
    
    fputs("bool isprime(int n) {\n", cout);
    fputs("    if (n <= 1) return false;\n", cout);
    fputs("    if (n <= 3) return true;\n", cout);
    fputs("    if (n % 2 == 0 || n % 3 == 0) return false;\n", cout);
    fputs("    for (int i = 5; i * i <= n; i += 6)\n", cout);
    fputs("        if (n % i == 0 || n % (i + 2) == 0) return false;\n", cout);
    fputs("    return true;\n}\n\n", cout);
    
    fputs("long long factorial(int n) {\n", cout);
    fputs("    long long result = 1;\n", cout);
    fputs("    for (int i = 2; i <= n; i++) result *= i;\n", cout);
    fputs("    return result;\n}\n\n", cout);
    
    fputs("bool ispalindrome(const char* str) {\n", cout);
    fputs("    int len = strlen(str);\n", cout);
    fputs("    for (int i = 0; i<len / 2; i++)\n", cout);
    fputs("        if (str[i] != str[len - i - 1]) return false;\n", cout);
    fputs("    return true;\n}\n\n", cout);
    
    fputs("int sum(int arr[], int size) {\n", cout);
    fputs("    int total = 0;\n", cout);
    fputs("    for (int i = 0; i < size; i++) total += arr[i];\n", cout);
    fputs("    return total;\n}\n\n", cout);
    
    fputs("int max(int arr[], int size) {\n", cout);
    fputs("    int m = arr[0];\n", cout);
    fputs("    for (int i = 1; i < size; i++)\n", cout);
    fputs("        if (arr[i] > m) m = arr[i];\n", cout);
    fputs("    return m;\n}\n\n", cout);
    
    fputs("int min(int arr[], int size) {\n", cout);
    fputs("    int m = arr[0];\n", cout);
    fputs("    for (int i = 1; i < size; i++)\n", cout);
    fputs("        if (arr[i] < m) m = arr[i];\n", cout);
    fputs("    return m;\n}\n\n", cout);
    
    fputs("double avg(int arr[], int size) {\n", cout);
    fputs("    return size ? (double)sum(arr, size) / size : 0.0;\n}\n\n", cout);
    
    fputs("void swap(int* a, int* b) {\n", cout);
    fputs("    int t = *a; *a = *b; *b = t;\n}\n\n", cout);
    
    write_slice_functions(cout);
    
    fputs("int main() {\n", cout);
    
    if (global_arr_length > 0) {
        fprintf(cout, "    int arr_length = %d;\n", global_arr_length);
    } else {
        fprintf(cout, "    int arr_length = 0;\n");
    }
    
    yylex();

    fputs("}\n", cout);
    
    fclose(tokout);
    fclose(cout);
    fclose(in);
    
    remove(temp_file);
    
    printf("Compilation successful! Output: out.c\n");
    return 0;
}