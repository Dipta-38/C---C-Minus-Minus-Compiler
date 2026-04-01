#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_PROGRAM,
    NODE_STATEMENT_LIST,
    NODE_DECLARATION,
    NODE_ARRAY_DECLARATION,
    NODE_IF_STATEMENT,
    NODE_WHILE_STATEMENT,
    NODE_DO_WHILE_STATEMENT,
    NODE_FOR_STATEMENT,
    NODE_RETURN_STATEMENT,
    NODE_BREAK_STATEMENT,
    NODE_CONTINUE_STATEMENT,
    NODE_BINARY_OPERATION,
    NODE_UNARY_OPERATION,
    NODE_INTEGER_LITERAL,
    NODE_FLOAT_LITERAL,
    NODE_STRING_LITERAL,
    NODE_CHAR_LITERAL,
    NODE_BOOLEAN_LITERAL,
    NODE_IDENTIFIER,
    NODE_ARRAY_ACCESS,
    NODE_ARRAY_SLICE,
    NODE_SLICE_EXPRESSION,
    NODE_FUNCTION_CALL,
    NODE_BUILTIN_CALL,
    NODE_OUT_STATEMENT,
    NODE_INP_STATEMENT
} NodeType;

typedef struct ASTNode {
    NodeType type;
    struct ASTNode *next;
    struct ASTNode *child;
    int line_number;
    
    union {
        struct {
            char *name;
        } identifier;
        struct {
            int value;
        } int_value;
        struct {
            double value;
        } float_value;
        struct {
            char *value;
        } string_value;
        struct {
            char value;
        } char_value;
        struct {
            char *type;
            char *name;
            struct ASTNode *value;
            struct ASTNode *size;
            struct ASTNode *initializer;
        } declaration;
        struct {
            struct ASTNode *condition;
            struct ASTNode *then_branch;
            struct ASTNode *else_branch;
        } if_stmt;
        struct {
            struct ASTNode *condition;
            struct ASTNode *body;
        } while_stmt;
        struct {
            struct ASTNode *body;
            struct ASTNode *condition;
        } do_while_stmt;
        struct {
            struct ASTNode *init;
            struct ASTNode *condition;
            struct ASTNode *increment;
            struct ASTNode *body;
        } for_stmt;
        struct {
            struct ASTNode *expression;
        } return_stmt;
        struct {
            char *operator;
            struct ASTNode *left;
            struct ASTNode *right;
        } binary_op;
        struct {
            char *operator;
            struct ASTNode *operand;
        } unary_op;
        struct {
            char *array_name;
            struct ASTNode *index;
        } array_access;
        struct {
            char *array_name;
            struct ASTNode *start;
            struct ASTNode *stop;
            struct ASTNode *step;
        } array_slice;
        struct {
            struct ASTNode *start;
            struct ASTNode *stop;
            struct ASTNode *step;
        } slice_expr;
        struct {
            char *name;
            struct ASTNode *arguments;
        } function_call;
        struct {
            char *name;
            struct ASTNode *arguments;
        } builtin_call;
        struct {
            struct ASTNode *expression;
        } out_stmt;
    } data;
} ASTNode;

// Constructor functions
ASTNode* create_program_node(ASTNode *statements);
ASTNode* create_statement_list_node(ASTNode *first, ASTNode *rest);
ASTNode* create_declaration_node(char *type, char *name, ASTNode *value);
ASTNode* create_array_declaration_node(char *type, char *name, ASTNode *size, ASTNode *initializer);
ASTNode* create_if_node(ASTNode *condition, ASTNode *then_branch, ASTNode *else_branch);
ASTNode* create_while_node(ASTNode *condition, ASTNode *body);
ASTNode* create_do_while_node(ASTNode *body, ASTNode *condition);
ASTNode* create_for_node(ASTNode *init, ASTNode *condition, ASTNode *increment, ASTNode *body);
ASTNode* create_return_node(ASTNode *expression);
ASTNode* create_break_node(void);
ASTNode* create_continue_node(void);
ASTNode* create_binary_op_node(char *operator, ASTNode *left, ASTNode *right);
ASTNode* create_unary_op_node(char *operator, ASTNode *operand);
ASTNode* create_int_node(int value);
ASTNode* create_float_node(double value);
ASTNode* create_string_node(char *value);
ASTNode* create_char_node(char value);
ASTNode* create_identifier_node(char *name);
ASTNode* create_array_access_node(char *name, ASTNode *index);
ASTNode* create_array_slice_node(char *name, ASTNode *start, ASTNode *stop, ASTNode *step);
ASTNode* create_slice_node(ASTNode *start, ASTNode *stop, ASTNode *step);
ASTNode* create_function_call_node(char *name, ASTNode *arguments);
ASTNode* create_builtin_node(char *name, ASTNode *arguments);
ASTNode* create_out_node(ASTNode *expression);
ASTNode* create_inp_node(ASTNode *expression);

// Code generation
void generate_code(ASTNode *node, FILE *output);
void free_ast(ASTNode *node);
void print_ast(ASTNode *node, int level);

#endif