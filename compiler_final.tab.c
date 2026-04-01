
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "compiler_final.y"

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



/* Line 189 of yacc.c  */
#line 95 "compiler_final.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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
     FOR = 273,
     IF_COLON = 274,
     ELIF_COLON = 275,
     WHILE_COLON = 276,
     DO = 277,
     ELSE = 278,
     BRK = 279,
     CNT = 280,
     RET = 281,
     OUT = 282,
     INP = 283,
     AND = 284,
     OR = 285,
     NOT = 286,
     MAIN_FUNC = 287,
     LET_PTR = 288,
     PRINT_SLICE = 289,
     FREE_SLICE = 290,
     GCD_FUNC = 291,
     ISPRIME_FUNC = 292,
     FACTORIAL_FUNC = 293,
     ISPALINDROME_FUNC = 294,
     SUM_FUNC = 295,
     MAX_FUNC = 296,
     MIN_FUNC = 297,
     AVG_FUNC = 298,
     SWAP_FUNC = 299,
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

/* Line 214 of yacc.c  */
#line 22 "compiler_final.y"

    int ival;
    double fval;
    char *sval;
    ASTNode *ast;



/* Line 214 of yacc.c  */
#line 215 "compiler_final.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 227 "compiler_final.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1007

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNRULES -- Number of states.  */
#define YYNSTATES  226

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    12,    14,    16,    18,    20,
      22,    24,    26,    30,    36,    46,    53,    59,    61,    63,
      65,    67,    69,    71,    73,    75,    77,    80,    84,    90,
     100,   111,   117,   125,   135,   139,   142,   145,   148,   150,
     152,   156,   158,   162,   164,   168,   170,   174,   178,   180,
     184,   188,   192,   196,   198,   202,   206,   208,   212,   216,
     220,   222,   225,   228,   231,   234,   237,   239,   244,   249,
     253,   258,   261,   264,   269,   274,   279,   284,   289,   294,
     299,   304,   309,   314,   319,   324,   329,   335,   339,   344,
     347,   350,   354,   357,   359,   361,   363,   365,   367,   371,
     373
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      77,     0,    -1,    32,    68,    78,    69,    -1,    -1,    78,
      79,    -1,    80,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    81,     3,    70,    -1,
      81,     3,    57,    88,    70,    -1,    81,     3,    73,    74,
      57,    68,   100,    69,    70,    -1,    81,     3,    73,     6,
      74,    70,    -1,    33,     3,    57,    88,    70,    -1,     8,
      -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
      -1,    14,    -1,    15,    -1,    70,    -1,    88,    70,    -1,
      68,    78,    69,    -1,    19,    88,    68,    78,    69,    -1,
      19,    88,    68,    78,    69,    23,    68,    78,    69,    -1,
      19,    88,    68,    78,    69,    20,    88,    68,    78,    69,
      -1,    21,    88,    68,    78,    69,    -1,    22,    68,    78,
      69,    21,    88,    70,    -1,    18,    66,    82,    82,    88,
      67,    68,    78,    69,    -1,    26,    88,    70,    -1,    26,
      70,    -1,    24,    70,    -1,    25,    70,    -1,    89,    -1,
      90,    -1,    96,    57,    89,    -1,    91,    -1,    90,    30,
      91,    -1,    92,    -1,    91,    29,    92,    -1,    93,    -1,
      92,    48,    93,    -1,    92,    49,    93,    -1,    94,    -1,
      93,    58,    94,    -1,    93,    59,    94,    -1,    93,    47,
      94,    -1,    93,    46,    94,    -1,    95,    -1,    94,    52,
      95,    -1,    94,    53,    95,    -1,    96,    -1,    95,    54,
      96,    -1,    95,    55,    96,    -1,    95,    56,    96,    -1,
      97,    -1,    50,    96,    -1,    51,    96,    -1,    31,    96,
      -1,    53,    96,    -1,    60,    96,    -1,    99,    -1,    97,
      73,    88,    74,    -1,    97,    73,    98,    74,    -1,    97,
      66,    67,    -1,    97,    66,   100,    67,    -1,    97,    50,
      -1,    97,    51,    -1,    27,    66,   100,    67,    -1,    28,
      66,   100,    67,    -1,    34,    66,    88,    67,    -1,    35,
      66,    88,    67,    -1,    36,    66,   100,    67,    -1,    37,
      66,    88,    67,    -1,    38,    66,    88,    67,    -1,    39,
      66,    88,    67,    -1,    40,    66,   100,    67,    -1,    41,
      66,   100,    67,    -1,    42,    66,   100,    67,    -1,    43,
      66,   100,    67,    -1,    44,    66,   100,    67,    -1,    88,
      72,    88,    72,    88,    -1,    88,    72,    88,    -1,    72,
      88,    72,    88,    -1,    72,    88,    -1,    88,    72,    -1,
      72,    72,    88,    -1,    72,    72,    -1,     3,    -1,     6,
      -1,     7,    -1,     4,    -1,     5,    -1,    66,    88,    67,
      -1,    88,    -1,   100,    71,    88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    94,    95,   101,   102,   103,   104,   105,
     106,   107,   111,   115,   119,   123,   127,   133,   134,   135,
     136,   137,   138,   139,   140,   144,   145,   149,   153,   156,
     159,   166,   169,   175,   181,   182,   183,   184,   188,   192,
     193,   199,   200,   206,   207,   213,   214,   217,   223,   224,
     227,   230,   233,   239,   240,   243,   249,   250,   253,   256,
     262,   263,   264,   265,   266,   267,   271,   272,   280,   290,
     298,   306,   309,   312,   315,   318,   321,   324,   327,   330,
     333,   336,   339,   342,   345,   348,   354,   357,   360,   363,
     366,   369,   372,   378,   379,   380,   381,   382,   383,   387,
     388
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "CHAR", "INT", "FLOAT",
  "LET", "DEC", "STR_TYPE", "CHR_TYPE", "BUL_TYPE", "NUL_TYPE", "CLS",
  "ENM", "TYP", "CON", "FOR", "IF_COLON", "ELIF_COLON", "WHILE_COLON",
  "DO", "ELSE", "BRK", "CNT", "RET", "OUT", "INP", "AND", "OR", "NOT",
  "MAIN_FUNC", "LET_PTR", "PRINT_SLICE", "FREE_SLICE", "GCD_FUNC",
  "ISPRIME_FUNC", "FACTORIAL_FUNC", "ISPALINDROME_FUNC", "SUM_FUNC",
  "MAX_FUNC", "MIN_FUNC", "AVG_FUNC", "SWAP_FUNC", "POW_OP", "GE", "LE",
  "EQ", "NE", "INC", "DECR", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "ASSIGN", "LT", "GT", "BITAND", "BITOR", "BITXOR", "BITNOT", "LSHIFT",
  "RSHIFT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMI", "COMMA",
  "COLON", "LBRACKET", "RBRACKET", "DOT", "$accept", "program",
  "statement_list", "statement", "declaration", "type_specifier",
  "expression_statement", "compound_statement", "selection_statement",
  "iteration_statement", "for_statement", "jump_statement", "expression",
  "assignment_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "slice_expression", "primary_expression",
  "argument_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    83,    84,    84,
      84,    85,    85,    86,    87,    87,    87,    87,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    93,    94,    94,    94,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    99,    99,    99,    99,    99,    99,   100,
     100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     9,     6,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     5,     9,
      10,     5,     7,     9,     3,     2,     2,     2,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     2,     2,     1,     4,     4,     3,
       4,     2,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     3,     4,     2,
       2,     3,     2,     1,     1,     1,     1,     1,     3,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,    93,    96,    97,    94,
      95,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     2,    25,     4,
       5,     0,     6,     7,     8,     9,    10,    11,     0,    38,
      39,    41,    43,    45,    48,    53,    56,    60,    66,     0,
       0,     0,     3,    36,    37,    35,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    64,    65,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,    72,     0,     0,     0,     3,
       3,     0,    34,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    27,
       0,    12,     0,    42,    56,    44,    46,    47,    52,    51,
      49,    50,    54,    55,    57,    58,    59,    40,    69,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,    74,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,    70,    92,    89,    90,    67,
      68,     0,    28,    31,     0,   100,    16,    13,     0,     0,
      91,     0,    87,     0,     0,     0,     0,    15,     0,    88,
       0,     3,     0,     3,    32,     0,    86,     0,     3,     0,
       0,    33,     0,    29,    14,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   162,    68,   124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
      12,   -32,    84,   -77,   -77,   270,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,    19,
     941,   941,    24,    23,    25,   797,    28,    32,   941,    96,
      34,    35,    36,    37,    38,    39,    55,    56,    57,    58,
      59,   941,   941,   941,   941,   941,   -77,   -77,   -77,   -77,
     -77,   123,   -77,   -77,   -77,   -77,   -77,   -77,    60,   -77,
      97,    99,   -39,   -13,     1,    33,    72,   -34,   -77,   848,
      65,    66,   -77,   -77,   -77,   -77,    61,   941,   941,   -77,
      78,   941,   941,   941,   941,   941,   941,   941,   941,   941,
     941,   941,   -77,   -77,   -77,   -77,    69,   338,   -49,   -77,
     941,   941,   941,   941,   941,   941,   941,   941,   941,   941,
     941,   941,   941,   941,   -77,   -77,   899,   158,   848,   -77,
     -77,   406,   -77,   -77,   -48,   -45,   941,    70,    71,   -40,
      74,    75,    77,   -30,   -29,   -24,   -12,   -11,   -77,   -77,
     941,   -77,     0,    99,   -77,   -39,   -13,   -13,     1,     1,
       1,     1,    33,    33,   -77,   -77,   -77,   -77,   -77,     5,
     200,   -54,    73,   941,   474,   542,   118,   -77,   941,   -77,
      76,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,    79,    80,    88,   -77,   941,    81,   941,   -77,
     -77,    83,    63,   -77,   941,   -77,   -77,   -77,    82,    87,
     -77,   941,    85,    90,   941,    91,    86,   -77,   941,   -77,
     941,   -77,    92,   -77,   -77,     4,   -77,   610,   -77,   678,
     100,   -77,   746,   -77,   -77,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -42,   -77,   -77,   -77,   -66,   -77,   -77,   -77,
     -77,   -77,   -20,    54,   -77,    51,   109,   -74,   -25,   -18,
       7,   -77,   -77,   -77,   -76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      70,    71,   125,   118,    97,    76,   183,   129,   140,   102,
     103,   133,   134,   135,   136,   137,   114,   115,   188,   167,
     189,   141,   169,   168,   142,    96,   168,   173,   146,   147,
     121,   168,   116,   104,   105,    79,     3,   177,   178,   117,
     159,   168,   168,   179,     1,   106,   107,   168,    92,    93,
      94,    95,   163,   108,   109,   180,   181,   123,   123,   168,
     168,   127,   128,   123,   130,   131,   132,   123,   123,   123,
     123,   123,   185,   220,   184,   168,   168,   164,   165,   148,
     149,   150,   151,   204,     4,    69,   205,   110,   111,   112,
     152,   153,    72,    73,    77,    74,   123,   161,    78,    80,
      81,    82,    83,    84,    85,    86,   170,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   154,   155,   156,
     182,    87,    88,    89,    90,    91,    98,   100,   101,   113,
      99,   122,   215,   119,   120,   126,   138,   171,   172,   194,
     187,   174,   175,   191,   176,   199,   196,   190,   195,   197,
     203,   143,   207,   201,   198,   208,   214,   210,   211,   213,
     218,     6,     7,     8,     9,    10,   200,   157,   202,   217,
     224,   219,     0,     0,   206,     0,   222,     0,     0,     0,
       0,   209,     0,     0,   212,    26,    27,     0,   123,    28,
     216,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     6,     7,     8,     9,    10,    41,    42,
     145,    43,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    45,     0,     0,    26,    27,     0,
     160,    28,     0,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     0,     0,     0,     0,
      41,    42,     0,    43,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,   186,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
       0,    21,    22,     0,    23,    24,    25,    26,    27,     0,
       0,    28,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     0,     0,     0,     0,
      41,    42,     0,    43,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    45,     0,    46,    47,
      48,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,     0,    21,
      22,     0,    23,    24,    25,    26,    27,     0,     0,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    45,     0,    46,   139,    48,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,     0,    21,    22,     0,
      23,    24,    25,    26,    27,     0,     0,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,    45,     0,    46,   166,    48,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,    19,    20,     0,    21,    22,     0,    23,    24,
      25,    26,    27,     0,     0,    28,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,    41,    42,     0,    43,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
      45,     0,    46,   192,    48,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,     0,    21,    22,     0,    23,    24,    25,    26,
      27,     0,     0,    28,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
       0,     0,    41,    42,     0,    43,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    45,     0,
      46,   193,    48,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
       0,    21,    22,     0,    23,    24,    25,    26,    27,     0,
       0,    28,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     0,     0,     0,     0,
      41,    42,     0,    43,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    45,     0,    46,   221,
      48,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,    19,    20,     0,    21,
      22,     0,    23,    24,    25,    26,    27,     0,     0,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    45,     0,    46,   223,    48,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,    19,    20,     0,    21,    22,     0,
      23,    24,    25,    26,    27,     0,     0,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       6,     7,     8,     9,    10,     0,    44,     0,     0,     0,
       0,     0,    45,     0,    46,   225,    48,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,    28,     0,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,     0,     0,    41,    42,     0,
      43,     6,     7,     8,     9,    10,     0,    44,     0,     0,
       0,     0,     0,    45,     0,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,    28,
       0,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     6,     7,     8,     9,    10,     0,    44,     0,
       0,     0,     0,     0,    45,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
      28,     0,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     6,     7,     8,     9,    10,    41,
      42,     0,    43,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,    45,   158,     0,    26,    27,
       0,     0,    28,     0,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,    41,    42,     0,    43,     0,     0,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,    45
};

static const yytype_int16 yycheck[] =
{
      20,    21,    78,    69,    46,    25,     6,    83,    57,    48,
      49,    87,    88,    89,    90,    91,    50,    51,    72,    67,
      74,    70,    67,    71,    73,    45,    71,    67,   102,   103,
      72,    71,    66,    46,    47,    28,    68,    67,    67,    73,
     116,    71,    71,    67,    32,    58,    59,    71,    41,    42,
      43,    44,   118,    52,    53,    67,    67,    77,    78,    71,
      71,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    67,    69,    74,    71,    71,   119,   120,   104,
     105,   106,   107,    20,     0,    66,    23,    54,    55,    56,
     108,   109,    68,    70,    66,    70,   116,   117,    66,     3,
      66,    66,    66,    66,    66,    66,   126,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     140,    66,    66,    66,    66,    66,     3,    30,    29,    57,
      70,    70,   208,    68,    68,    57,    67,    67,    67,    21,
     160,    67,    67,   163,    67,    57,    70,    74,   168,    70,
      67,   100,    70,    72,    74,    68,    70,    72,    68,    68,
      68,     3,     4,     5,     6,     7,   186,   113,   188,   211,
      70,   213,    -1,    -1,   194,    -1,   218,    -1,    -1,    -1,
      -1,   201,    -1,    -1,   204,    27,    28,    -1,   208,    31,
     210,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     3,     4,     5,     6,     7,    50,    51,
     101,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    27,    28,    -1,
      72,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    72,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,    21,    22,    -1,    24,    25,    26,    27,    28,    -1,
      -1,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,
      70,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    28,    -1,    -1,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    -1,    21,    22,    -1,
      24,    25,    26,    27,    28,    -1,    -1,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    68,    69,    70,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    -1,    21,    22,    -1,    24,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    68,    69,    70,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      68,    69,    70,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,    21,    22,    -1,    24,    25,    26,    27,    28,    -1,
      -1,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,
      70,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    28,    -1,    -1,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    -1,    21,    22,    -1,
      24,    25,    26,    27,    28,    -1,    -1,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    53,
       3,     4,     5,     6,     7,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      53,     3,     4,     5,     6,     7,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    53,     3,     4,     5,     6,     7,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     3,     4,     5,     6,     7,    50,
      51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    50,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    77,    68,     0,    78,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    18,
      19,    21,    22,    24,    25,    26,    27,    28,    31,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    50,    51,    53,    60,    66,    68,    69,    70,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    99,    66,
      88,    88,    68,    70,    70,    70,    88,    66,    66,    96,
       3,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    96,    96,    96,    96,    88,    78,     3,    70,
      30,    29,    48,    49,    46,    47,    58,    59,    52,    53,
      54,    55,    56,    57,    50,    51,    66,    73,    82,    68,
      68,    78,    70,    88,   100,   100,    57,    88,    88,   100,
      88,    88,    88,   100,   100,   100,   100,   100,    67,    69,
      57,    70,    73,    91,    96,    92,    93,    93,    94,    94,
      94,    94,    95,    95,    96,    96,    96,    89,    67,   100,
      72,    88,    98,    82,    78,    78,    69,    67,    71,    67,
      88,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    88,     6,    74,    67,    72,    88,    72,    74,
      74,    88,    69,    69,    21,    88,    70,    70,    74,    57,
      88,    72,    88,    67,    20,    23,    88,    70,    68,    88,
      72,    68,    88,    68,    70,   100,    88,    78,    68,    78,
      69,    69,    78,    69,    70,    69
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 88 "compiler_final.y"
    {
        program_ast = create_program_node((yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 94 "compiler_final.y"
    { (yyval.ast) = NULL; ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 95 "compiler_final.y"
    {
        (yyval.ast) = create_statement_list_node((yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast));
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 101 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 102 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 103 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 104 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 105 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 106 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 107 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 111 "compiler_final.y"
    {
        (yyval.ast) = create_declaration_node((yyvsp[(1) - (3)].ast)->data.identifier.name, (yyvsp[(2) - (3)].sval), NULL);
        free_ast((yyvsp[(1) - (3)].ast));
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 115 "compiler_final.y"
    {
        (yyval.ast) = create_declaration_node((yyvsp[(1) - (5)].ast)->data.identifier.name, (yyvsp[(2) - (5)].sval), (yyvsp[(4) - (5)].ast));
        free_ast((yyvsp[(1) - (5)].ast));
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 119 "compiler_final.y"
    {
        (yyval.ast) = create_array_declaration_node((yyvsp[(1) - (9)].ast)->data.identifier.name, (yyvsp[(2) - (9)].sval), NULL, (yyvsp[(7) - (9)].ast));
        free_ast((yyvsp[(1) - (9)].ast));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 123 "compiler_final.y"
    {
        (yyval.ast) = create_array_declaration_node((yyvsp[(1) - (6)].ast)->data.identifier.name, (yyvsp[(2) - (6)].sval), create_int_node((yyvsp[(4) - (6)].ival)), NULL);
        free_ast((yyvsp[(1) - (6)].ast));
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 127 "compiler_final.y"
    {
        (yyval.ast) = create_declaration_node("int*", (yyvsp[(2) - (5)].sval), (yyvsp[(4) - (5)].ast));
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 133 "compiler_final.y"
    { (yyval.ast) = create_identifier_node("int"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 134 "compiler_final.y"
    { (yyval.ast) = create_identifier_node("double"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 135 "compiler_final.y"
    { (yyval.ast) = create_identifier_node("const char*"); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 136 "compiler_final.y"
    { (yyval.ast) = create_identifier_node("char"); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 137 "compiler_final.y"
    { (yyval.ast) = create_identifier_node("bool"); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 138 "compiler_final.y"
    { (yyval.ast) = create_identifier_node("void"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 139 "compiler_final.y"
    { (yyval.ast) = create_identifier_node("struct"); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 140 "compiler_final.y"
    { (yyval.ast) = create_identifier_node("enum"); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 144 "compiler_final.y"
    { (yyval.ast) = NULL; ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 145 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (2)].ast); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 149 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(2) - (3)].ast); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 153 "compiler_final.y"
    {
        (yyval.ast) = create_if_node((yyvsp[(2) - (5)].ast), (yyvsp[(4) - (5)].ast), NULL);
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 156 "compiler_final.y"
    {
        (yyval.ast) = create_if_node((yyvsp[(2) - (9)].ast), (yyvsp[(4) - (9)].ast), (yyvsp[(8) - (9)].ast));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 159 "compiler_final.y"
    {
        ASTNode *elif_node = create_if_node((yyvsp[(7) - (10)].ast), (yyvsp[(9) - (10)].ast), NULL);
        (yyval.ast) = create_if_node((yyvsp[(2) - (10)].ast), (yyvsp[(4) - (10)].ast), elif_node);
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 166 "compiler_final.y"
    {
        (yyval.ast) = create_while_node((yyvsp[(2) - (5)].ast), (yyvsp[(4) - (5)].ast));
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 169 "compiler_final.y"
    {
        (yyval.ast) = create_do_while_node((yyvsp[(3) - (7)].ast), (yyvsp[(6) - (7)].ast));
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 175 "compiler_final.y"
    {
        (yyval.ast) = create_for_node((yyvsp[(3) - (9)].ast), (yyvsp[(4) - (9)].ast), (yyvsp[(5) - (9)].ast), (yyvsp[(8) - (9)].ast));
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 181 "compiler_final.y"
    { (yyval.ast) = create_return_node((yyvsp[(2) - (3)].ast)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 182 "compiler_final.y"
    { (yyval.ast) = create_return_node(NULL); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 183 "compiler_final.y"
    { (yyval.ast) = create_break_node(); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 184 "compiler_final.y"
    { (yyval.ast) = create_continue_node(); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 188 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 192 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 193 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("=", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 199 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 200 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("||", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 206 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 207 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("&&", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 213 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 214 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("==", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 217 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("!=", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 223 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 224 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("<", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 227 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node(">", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 230 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("<=", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 233 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node(">=", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 239 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 240 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("+", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 243 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("-", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 249 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 250 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("*", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 253 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("/", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 256 "compiler_final.y"
    {
        (yyval.ast) = create_binary_op_node("%", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 262 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 263 "compiler_final.y"
    { (yyval.ast) = create_unary_op_node("++", (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 264 "compiler_final.y"
    { (yyval.ast) = create_unary_op_node("--", (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 265 "compiler_final.y"
    { (yyval.ast) = create_unary_op_node("!", (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 266 "compiler_final.y"
    { (yyval.ast) = create_unary_op_node("-", (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 267 "compiler_final.y"
    { (yyval.ast) = create_unary_op_node("&", (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 271 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 272 "compiler_final.y"
    {
        if ((yyvsp[(1) - (4)].ast)->type == NODE_IDENTIFIER) {
            (yyval.ast) = create_array_access_node((yyvsp[(1) - (4)].ast)->data.identifier.name, (yyvsp[(3) - (4)].ast));
            free_ast((yyvsp[(1) - (4)].ast));
        } else {
            (yyval.ast) = NULL;
        }
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 280 "compiler_final.y"
    {
        if ((yyvsp[(1) - (4)].ast)->type == NODE_IDENTIFIER) {
            (yyval.ast) = create_array_slice_node((yyvsp[(1) - (4)].ast)->data.identifier.name, 
                   (yyvsp[(3) - (4)].ast)->data.slice_expr.start, (yyvsp[(3) - (4)].ast)->data.slice_expr.stop, (yyvsp[(3) - (4)].ast)->data.slice_expr.step);
            free_ast((yyvsp[(1) - (4)].ast));
            free_ast((yyvsp[(3) - (4)].ast));
        } else {
            (yyval.ast) = NULL;
        }
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 290 "compiler_final.y"
    {
        if ((yyvsp[(1) - (3)].ast)->type == NODE_IDENTIFIER) {
            (yyval.ast) = create_function_call_node((yyvsp[(1) - (3)].ast)->data.identifier.name, NULL);
            free_ast((yyvsp[(1) - (3)].ast));
        } else {
            (yyval.ast) = NULL;
        }
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 298 "compiler_final.y"
    {
        if ((yyvsp[(1) - (4)].ast)->type == NODE_IDENTIFIER) {
            (yyval.ast) = create_function_call_node((yyvsp[(1) - (4)].ast)->data.identifier.name, (yyvsp[(3) - (4)].ast));
            free_ast((yyvsp[(1) - (4)].ast));
        } else {
            (yyval.ast) = NULL;
        }
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 306 "compiler_final.y"
    {
        (yyval.ast) = create_unary_op_node("post++", (yyvsp[(1) - (2)].ast));
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 309 "compiler_final.y"
    {
        (yyval.ast) = create_unary_op_node("post--", (yyvsp[(1) - (2)].ast));
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 312 "compiler_final.y"
    {
        (yyval.ast) = create_out_node((yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 315 "compiler_final.y"
    {
        (yyval.ast) = create_inp_node((yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 318 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("print_int_slice", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 321 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("free_int_slice", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 324 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("gcd", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 327 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("isprime", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 330 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("factorial", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 333 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("ispalindrome", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 336 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("sum", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 339 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("max", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 342 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("min", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 345 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("avg", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 348 "compiler_final.y"
    {
        (yyval.ast) = create_builtin_node("swap", (yyvsp[(3) - (4)].ast));
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 354 "compiler_final.y"
    {
        (yyval.ast) = create_slice_node((yyvsp[(1) - (5)].ast), (yyvsp[(3) - (5)].ast), (yyvsp[(5) - (5)].ast));
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 357 "compiler_final.y"
    {
        (yyval.ast) = create_slice_node((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), NULL);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 360 "compiler_final.y"
    {
        (yyval.ast) = create_slice_node(NULL, (yyvsp[(2) - (4)].ast), (yyvsp[(4) - (4)].ast));
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 363 "compiler_final.y"
    {
        (yyval.ast) = create_slice_node(NULL, (yyvsp[(2) - (2)].ast), NULL);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 366 "compiler_final.y"
    {
        (yyval.ast) = create_slice_node((yyvsp[(1) - (2)].ast), NULL, NULL);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 369 "compiler_final.y"
    {
        (yyval.ast) = create_slice_node(NULL, NULL, (yyvsp[(3) - (3)].ast));
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 372 "compiler_final.y"
    {
        (yyval.ast) = create_slice_node(NULL, NULL, NULL);
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 378 "compiler_final.y"
    { (yyval.ast) = create_identifier_node((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 379 "compiler_final.y"
    { (yyval.ast) = create_int_node((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 380 "compiler_final.y"
    { (yyval.ast) = create_float_node((yyvsp[(1) - (1)].fval)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 381 "compiler_final.y"
    { (yyval.ast) = create_string_node((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 382 "compiler_final.y"
    { (yyval.ast) = create_char_node((yyvsp[(1) - (1)].sval)[1]); free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 383 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(2) - (3)].ast); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 387 "compiler_final.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 388 "compiler_final.y"
    {
        ASTNode *last = (yyvsp[(1) - (3)].ast);
        while (last->next) last = last->next;
        last->next = (yyvsp[(3) - (3)].ast);
        (yyval.ast) = (yyvsp[(1) - (3)].ast);
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2614 "compiler_final.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 396 "compiler_final.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s near '%s'\n", yylineno, s, yytext);
}
