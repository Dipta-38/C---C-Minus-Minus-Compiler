#include "ast.h"

ASTNode* create_node(NodeType type) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    memset(node, 0, sizeof(ASTNode));
    node->type = type;
    return node;
}

ASTNode* create_program_node(ASTNode *statements) {
    ASTNode *node = create_node(NODE_PROGRAM);
    node->child = statements;
    return node;
}

ASTNode* create_statement_list_node(ASTNode *first, ASTNode *rest) {
    if (!first) return rest;
    ASTNode *node = first;
    while (node->next) node = node->next;
    node->next = rest;
    return first;
}

ASTNode* create_declaration_node(char *type, char *name, ASTNode *value) {
    ASTNode *node = create_node(NODE_DECLARATION);
    node->data.declaration.type = strdup(type);
    node->data.declaration.name = strdup(name);
    node->data.declaration.value = value;
    return node;
}

ASTNode* create_array_declaration_node(char *type, char *name, ASTNode *size, ASTNode *initializer) {
    ASTNode *node = create_node(NODE_ARRAY_DECLARATION);
    node->data.declaration.type = strdup(type);
    node->data.declaration.name = strdup(name);
    node->data.declaration.size = size;
    node->data.declaration.initializer = initializer;
    return node;
}

ASTNode* create_if_node(ASTNode *condition, ASTNode *then_branch, ASTNode *else_branch) {
    ASTNode *node = create_node(NODE_IF_STATEMENT);
    node->data.if_stmt.condition = condition;
    node->data.if_stmt.then_branch = then_branch;
    node->data.if_stmt.else_branch = else_branch;
    return node;
}

ASTNode* create_while_node(ASTNode *condition, ASTNode *body) {
    ASTNode *node = create_node(NODE_WHILE_STATEMENT);
    node->data.while_stmt.condition = condition;
    node->data.while_stmt.body = body;
    return node;
}

ASTNode* create_do_while_node(ASTNode *body, ASTNode *condition) {
    ASTNode *node = create_node(NODE_DO_WHILE_STATEMENT);
    node->data.do_while_stmt.body = body;
    node->data.do_while_stmt.condition = condition;
    return node;
}

ASTNode* create_return_node(ASTNode *expression) {
    ASTNode *node = create_node(NODE_RETURN_STATEMENT);
    node->data.return_stmt.expression = expression;
    return node;
}

ASTNode* create_break_node(void) {
    return create_node(NODE_BREAK_STATEMENT);
}

ASTNode* create_continue_node(void) {
    return create_node(NODE_CONTINUE_STATEMENT);
}

ASTNode* create_binary_op_node(char *operator, ASTNode *left, ASTNode *right) {
    ASTNode *node = create_node(NODE_BINARY_OPERATION);
    node->data.binary_op.operator = strdup(operator);
    node->data.binary_op.left = left;
    node->data.binary_op.right = right;
    return node;
}

ASTNode* create_unary_op_node(char *operator, ASTNode *operand) {
    ASTNode *node = create_node(NODE_UNARY_OPERATION);
    node->data.unary_op.operator = strdup(operator);
    node->data.unary_op.operand = operand;
    return node;
}

ASTNode* create_int_node(int value) {
    ASTNode *node = create_node(NODE_INTEGER_LITERAL);
    node->data.int_value.value = value;
    return node;
}

ASTNode* create_float_node(double value) {
    ASTNode *node = create_node(NODE_FLOAT_LITERAL);
    node->data.float_value.value = value;
    return node;
}

ASTNode* create_string_node(char *value) {
    ASTNode *node = create_node(NODE_STRING_LITERAL);
    node->data.string_value.value = strdup(value);
    return node;
}

ASTNode* create_char_node(char value) {
    ASTNode *node = create_node(NODE_CHAR_LITERAL);
    node->data.char_value.value = value;
    return node;
}

ASTNode* create_identifier_node(char *name) {
    ASTNode *node = create_node(NODE_IDENTIFIER);
    node->data.identifier.name = strdup(name);
    return node;
}

ASTNode* create_array_access_node(char *name, ASTNode *index) {
    ASTNode *node = create_node(NODE_ARRAY_ACCESS);
    node->data.array_access.array_name = strdup(name);
    node->data.array_access.index = index;
    return node;
}

ASTNode* create_array_slice_node(char *name, ASTNode *start, ASTNode *stop, ASTNode *step) {
    ASTNode *node = create_node(NODE_ARRAY_SLICE);
    node->data.array_slice.array_name = strdup(name);
    node->data.array_slice.start = start;
    node->data.array_slice.stop = stop;
    node->data.array_slice.step = step;
    return node;
}

ASTNode* create_slice_node(ASTNode *start, ASTNode *stop, ASTNode *step) {
    ASTNode *node = create_node(NODE_SLICE_EXPRESSION);
    node->data.slice_expr.start = start;
    node->data.slice_expr.stop = stop;
    node->data.slice_expr.step = step;
    return node;
}

ASTNode* create_function_call_node(char *name, ASTNode *arguments) {
    ASTNode *node = create_node(NODE_FUNCTION_CALL);
    node->data.function_call.name = strdup(name);
    node->data.function_call.arguments = arguments;
    return node;
}

ASTNode* create_builtin_node(char *name, ASTNode *arguments) {
    ASTNode *node = create_node(NODE_BUILTIN_CALL);
    node->data.builtin_call.name = strdup(name);
    node->data.builtin_call.arguments = arguments;
    return node;
}

ASTNode* create_out_node(ASTNode *expression) {
    ASTNode *node = create_node(NODE_OUT_STATEMENT);
    node->data.out_stmt.expression = expression;
    return node;
}

ASTNode* create_inp_node(ASTNode *expression) {
    ASTNode *node = create_node(NODE_INP_STATEMENT);
    node->data.out_stmt.expression = expression;
    return node;
}

void generate_expression(ASTNode *node, FILE *output) {
    if (!node) return;
    
    switch (node->type) {
        case NODE_INTEGER_LITERAL:
            fprintf(output, "%d", node->data.int_value.value);
            break;
        case NODE_FLOAT_LITERAL:
            fprintf(output, "%f", node->data.float_value.value);
            break;
        case NODE_STRING_LITERAL:
            fprintf(output, "%s", node->data.string_value.value);
            break;
        case NODE_CHAR_LITERAL:
            fprintf(output, "'%c'", node->data.char_value.value);
            break;
        case NODE_IDENTIFIER:
            fprintf(output, "%s", node->data.identifier.name);
            break;
        case NODE_BINARY_OPERATION:
            if (strcmp(node->data.binary_op.operator, "**") == 0) {
                fprintf(output, "(int)pow(");
                generate_expression(node->data.binary_op.left, output);
                fprintf(output, ", ");
                generate_expression(node->data.binary_op.right, output);
                fprintf(output, ")");
            } else {
                generate_expression(node->data.binary_op.left, output);
                fprintf(output, " %s ", node->data.binary_op.operator);
                generate_expression(node->data.binary_op.right, output);
            }
            break;
        case NODE_UNARY_OPERATION:
            if (strcmp(node->data.unary_op.operator, "post++") == 0) {
                generate_expression(node->data.unary_op.operand, output);
                fprintf(output, "++");
            } else if (strcmp(node->data.unary_op.operator, "post--") == 0) {
                generate_expression(node->data.unary_op.operand, output);
                fprintf(output, "--");
            } else {
                fprintf(output, "%s", node->data.unary_op.operator);
                generate_expression(node->data.unary_op.operand, output);
            }
            break;
        case NODE_ARRAY_ACCESS:
            fprintf(output, "%s[", node->data.array_access.array_name);
            generate_expression(node->data.array_access.index, output);
            fprintf(output, "]");
            break;
        case NODE_FUNCTION_CALL:
            fprintf(output, "%s(", node->data.function_call.name);
            {
                ASTNode *arg = node->data.function_call.arguments;
                while (arg) {
                    generate_expression(arg, output);
                    arg = arg->next;
                    if (arg) fprintf(output, ", ");
                }
            }
            fprintf(output, ")");
            break;
        case NODE_BUILTIN_CALL:
            fprintf(output, "%s(", node->data.builtin_call.name);
            {
                ASTNode *arg = node->data.builtin_call.arguments;
                while (arg) {
                    generate_expression(arg, output);
                    arg = arg->next;
                    if (arg) fprintf(output, ", ");
                }
            }
            fprintf(output, ")");
            break;
        default:
            break;
    }
}

void generate_code(ASTNode *node, FILE *output) {
    if (!node) return;
    
    switch (node->type) {
        case NODE_PROGRAM:
            fprintf(output, "#include <stdio.h>\n");
            fprintf(output, "#include <stdbool.h>\n");
            fprintf(output, "#include <math.h>\n");
            fprintf(output, "#include <string.h>\n");
            fprintf(output, "#include <stdlib.h>\n\n");
            fprintf(output, "int main() {\n");
            generate_code(node->child, output);
            fprintf(output, "    return 0;\n");
            fprintf(output, "}\n");
            break;
            
        case NODE_DECLARATION:
            fprintf(output, "    %s %s", node->data.declaration.type, node->data.declaration.name);
            if (node->data.declaration.value) {
                fprintf(output, " = ");
                generate_expression(node->data.declaration.value, output);
            }
            fprintf(output, ";\n");
            break;
            
        case NODE_ARRAY_DECLARATION:
            fprintf(output, "    %s %s", node->data.declaration.type, node->data.declaration.name);
            if (node->data.declaration.size) {
                fprintf(output, "[");
                generate_expression(node->data.declaration.size, output);
                fprintf(output, "]");
            } else {
                fprintf(output, "[]");
            }
            if (node->data.declaration.initializer) {
                fprintf(output, " = {");
                ASTNode *init = node->data.declaration.initializer;
                while (init) {
                    generate_expression(init, output);
                    init = init->next;
                    if (init) fprintf(output, ", ");
                }
                fprintf(output, "}");
            }
            fprintf(output, ";\n");
            break;
            
        case NODE_IF_STATEMENT:
            fprintf(output, "    if (");
            generate_expression(node->data.if_stmt.condition, output);
            fprintf(output, ") {\n");
            generate_code(node->data.if_stmt.then_branch, output);
            fprintf(output, "    }");
            if (node->data.if_stmt.else_branch) {
                fprintf(output, " else {\n");
                generate_code(node->data.if_stmt.else_branch, output);
                fprintf(output, "    }");
            }
            fprintf(output, "\n");
            break;
            
        case NODE_WHILE_STATEMENT:
            fprintf(output, "    while (");
            generate_expression(node->data.while_stmt.condition, output);
            fprintf(output, ") {\n");
            generate_code(node->data.while_stmt.body, output);
            fprintf(output, "    }\n");
            break;
            
        case NODE_DO_WHILE_STATEMENT:
            fprintf(output, "    do {\n");
            generate_code(node->data.do_while_stmt.body, output);
            fprintf(output, "    } while (");
            generate_expression(node->data.do_while_stmt.condition, output);
            fprintf(output, ");\n");
            break;
            
        case NODE_RETURN_STATEMENT:
            fprintf(output, "    return ");
            if (node->data.return_stmt.expression) {
                generate_expression(node->data.return_stmt.expression, output);
            }
            fprintf(output, ";\n");
            break;
            
        case NODE_BREAK_STATEMENT:
            fprintf(output, "    break;\n");
            break;
            
        case NODE_CONTINUE_STATEMENT:
            fprintf(output, "    continue;\n");
            break;
            
        case NODE_OUT_STATEMENT:
            fprintf(output, "    printf(");
            generate_expression(node->data.out_stmt.expression, output);
            fprintf(output, ");\n");
            break;
            
        default:
            if (node->child) {
                generate_code(node->child, output);
            }
            if (node->next) {
                generate_code(node->next, output);
            }
            break;
    }
}

void print_ast(ASTNode *node, int level) {
    if (!node) return;
    
    for (int i = 0; i < level; i++) printf("  ");
    
    switch (node->type) {
        case NODE_PROGRAM:
            printf("PROGRAM\n");
            break;
        case NODE_DECLARATION:
            printf("DECLARATION: %s %s\n", node->data.declaration.type, node->data.declaration.name);
            break;
        case NODE_ARRAY_DECLARATION:
            printf("ARRAY_DECLARATION: %s %s\n", node->data.declaration.type, node->data.declaration.name);
            break;
        case NODE_IF_STATEMENT:
            printf("IF_STATEMENT\n");
            break;
        case NODE_WHILE_STATEMENT:
            printf("WHILE_STATEMENT\n");
            break;
        case NODE_DO_WHILE_STATEMENT:
            printf("DO_WHILE_STATEMENT\n");
            break;
        case NODE_RETURN_STATEMENT:
            printf("RETURN_STATEMENT\n");
            break;
        case NODE_BREAK_STATEMENT:
            printf("BREAK\n");
            break;
        case NODE_CONTINUE_STATEMENT:
            printf("CONTINUE\n");
            break;
        case NODE_BINARY_OPERATION:
            printf("BINARY_OP: %s\n", node->data.binary_op.operator);
            break;
        case NODE_UNARY_OPERATION:
            printf("UNARY_OP: %s\n", node->data.unary_op.operator);
            break;
        case NODE_INTEGER_LITERAL:
            printf("INT: %d\n", node->data.int_value.value);
            break;
        case NODE_FLOAT_LITERAL:
            printf("FLOAT: %f\n", node->data.float_value.value);
            break;
        case NODE_STRING_LITERAL:
            printf("STRING: %s\n", node->data.string_value.value);
            break;
        case NODE_CHAR_LITERAL:
            printf("CHAR: '%c'\n", node->data.char_value.value);
            break;
        case NODE_IDENTIFIER:
            printf("IDENTIFIER: %s\n", node->data.identifier.name);
            break;
        case NODE_ARRAY_ACCESS:
            printf("ARRAY_ACCESS: %s\n", node->data.array_access.array_name);
            break;
        case NODE_ARRAY_SLICE:
            printf("ARRAY_SLICE: %s\n", node->data.array_slice.array_name);
            break;
        case NODE_FUNCTION_CALL:
            printf("FUNCTION_CALL: %s\n", node->data.function_call.name);
            break;
        case NODE_BUILTIN_CALL:
            printf("BUILTIN_CALL: %s\n", node->data.builtin_call.name);
            break;
        case NODE_OUT_STATEMENT:
            printf("OUT_STATEMENT\n");
            break;
        default:
            printf("NODE_TYPE: %d\n", node->type);
            break;
    }
    
    print_ast(node->child, level + 1);
    print_ast(node->next, level);
}

void free_ast(ASTNode *node) {
    if (!node) return;
    free_ast(node->child);
    free_ast(node->next);
    
    switch (node->type) {
        case NODE_IDENTIFIER:
            free(node->data.identifier.name);
            break;
        case NODE_DECLARATION:
        case NODE_ARRAY_DECLARATION:
            free(node->data.declaration.type);
            free(node->data.declaration.name);
            break;
        case NODE_BINARY_OPERATION:
            free(node->data.binary_op.operator);
            break;
        case NODE_UNARY_OPERATION:
            free(node->data.unary_op.operator);
            break;
        case NODE_ARRAY_ACCESS:
            free(node->data.array_access.array_name);
            break;
        case NODE_ARRAY_SLICE:
            free(node->data.array_slice.array_name);
            break;
        case NODE_FUNCTION_CALL:
            free(node->data.function_call.name);
            break;
        case NODE_BUILTIN_CALL:
            free(node->data.builtin_call.name);
            break;
        case NODE_STRING_LITERAL:
            free(node->data.string_value.value);
            break;
    }
    
    free(node);
}