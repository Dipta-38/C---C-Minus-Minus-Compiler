
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     STRING = 259,
     CHAR = 260,
     INT = 261,
     FLOAT = 262,
     LET = 263,
     DEC = 264,
     STR_TYPE = 265,
     CHR_TYPE = 266,
     BUL_TYPE = 267,
     NUL_TYPE = 268,
     CLS = 269,
     ENM = 270,
     TYP = 271,
     CON = 272,
     IF_COLON = 273,
     ELIF_COLON = 274,
     WHILE_COLON = 275,
     DO = 276,
     ELSE = 277,
     BRK = 278,
     CNT = 279,
     RET = 280,
     OUT = 281,
     INP = 282,
     AND = 283,
     OR = 284,
     NOT = 285,
     MAIN_FUNC = 286,
     LET_PTR = 287,
     PRINT_SLICE = 288,
     FREE_SLICE = 289,
     GCD_FUNC = 290,
     ISPRIME_FUNC = 291,
     FACTORIAL_FUNC = 292,
     ISPALINDROME_FUNC = 293,
     SUM_FUNC = 294,
     MAX_FUNC = 295,
     MIN_FUNC = 296,
     AVG_FUNC = 297,
     SWAP_FUNC = 298,
     POW_EXPR = 299,
     POW_OP = 300,
     GE = 301,
     LE = 302,
     EQ = 303,
     NE = 304,
     INC = 305,
     DECR = 306,
     PLUS = 307,
     MINUS = 308,
     MUL = 309,
     DIV = 310,
     MOD = 311,
     ASSIGN = 312,
     LT = 313,
     GT = 314,
     BITAND = 315,
     BITOR = 316,
     BITXOR = 317,
     BITNOT = 318,
     LSHIFT = 319,
     RSHIFT = 320,
     LPAREN = 321,
     RPAREN = 322,
     LBRACE = 323,
     RBRACE = 324,
     SEMI = 325,
     COMMA = 326,
     COLON = 327,
     LBRACKET = 328,
     RBRACKET = 329,
     DOT = 330
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 24 "cmm_parser_fixed.y"

    int ival;
    double fval;
    char *sval;



/* Line 1676 of yacc.c  */
#line 135 "cmm_parser_fixed.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


