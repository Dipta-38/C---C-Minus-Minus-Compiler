
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
#line 1 "cmm_parser.y"

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



/* Line 189 of yacc.c  */
#line 97 "cmm_parser.tab.c"

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

/* Line 214 of yacc.c  */
#line 24 "cmm_parser.y"

    int ival;
    double fval;
    char *sval;



/* Line 214 of yacc.c  */
#line 216 "cmm_parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 228 "cmm_parser.tab.c"

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
#define YYLAST   761

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  206

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
       0,     0,     3,     4,    10,    11,    14,    16,    18,    20,
      22,    24,    26,    28,    32,    38,    48,    55,    61,    63,
      65,    67,    69,    71,    73,    75,    77,    79,    82,    86,
      92,   102,   113,   119,   127,   131,   134,   137,   140,   142,
     144,   148,   150,   154,   156,   160,   162,   166,   170,   172,
     176,   180,   184,   188,   190,   194,   198,   200,   204,   208,
     212,   214,   217,   220,   223,   226,   229,   231,   236,   240,
     245,   248,   251,   256,   261,   266,   271,   276,   281,   286,
     291,   296,   301,   306,   311,   316,   318,   320,   322,   324,
     326,   330,   332
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      77,     0,    -1,    -1,    31,    68,    78,    79,    69,    -1,
      -1,    79,    80,    -1,    81,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    82,     3,
      70,    -1,    82,     3,    57,    89,    70,    -1,    82,     3,
      73,    74,    57,    68,   100,    69,    70,    -1,    82,     3,
      73,     6,    74,    70,    -1,    32,     3,    57,    89,    70,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    15,    -1,    70,    -1,    89,
      70,    -1,    68,    79,    69,    -1,    18,    89,    68,    79,
      69,    -1,    18,    89,    68,    79,    69,    22,    68,    79,
      69,    -1,    18,    89,    68,    79,    69,    19,    89,    68,
      79,    69,    -1,    20,    89,    68,    79,    69,    -1,    21,
      68,    79,    69,    20,    89,    70,    -1,    25,    89,    70,
      -1,    25,    70,    -1,    23,    70,    -1,    24,    70,    -1,
      90,    -1,    91,    -1,    97,    57,    90,    -1,    92,    -1,
      91,    29,    92,    -1,    93,    -1,    92,    28,    93,    -1,
      94,    -1,    93,    48,    94,    -1,    93,    49,    94,    -1,
      95,    -1,    94,    58,    95,    -1,    94,    59,    95,    -1,
      94,    47,    95,    -1,    94,    46,    95,    -1,    96,    -1,
      95,    52,    96,    -1,    95,    53,    96,    -1,    97,    -1,
      96,    54,    97,    -1,    96,    55,    97,    -1,    96,    56,
      97,    -1,    98,    -1,    50,    97,    -1,    51,    97,    -1,
      30,    97,    -1,    53,    97,    -1,    60,    97,    -1,    99,
      -1,    98,    73,    89,    74,    -1,    98,    66,    67,    -1,
      98,    66,   100,    67,    -1,    98,    50,    -1,    98,    51,
      -1,    26,    66,   100,    67,    -1,    27,    66,   100,    67,
      -1,    33,    66,    89,    67,    -1,    34,    66,    89,    67,
      -1,    35,    66,   100,    67,    -1,    36,    66,    89,    67,
      -1,    37,    66,    89,    67,    -1,    38,    66,    89,    67,
      -1,    39,    66,   100,    67,    -1,    40,    66,   100,    67,
      -1,    41,    66,   100,    67,    -1,    42,    66,   100,    67,
      -1,    43,    66,   100,    67,    -1,     3,    -1,     6,    -1,
       7,    -1,     4,    -1,     5,    -1,    66,    89,    67,    -1,
      89,    -1,   100,    71,    89,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    88,    98,   100,   104,   105,   106,   107,
     108,   109,   110,   114,   118,   122,   126,   130,   137,   138,
     139,   140,   141,   142,   143,   144,   148,   149,   156,   160,
     165,   171,   181,   189,   197,   201,   204,   207,   213,   217,
     218,   227,   228,   237,   238,   247,   248,   254,   263,   264,
     270,   276,   282,   291,   292,   298,   307,   308,   314,   320,
     329,   330,   336,   342,   348,   354,   363,   364,   370,   376,
     382,   388,   394,   400,   406,   412,   418,   424,   430,   436,
     442,   448,   454,   460,   466,   475,   476,   481,   486,   487,
     488,   497,   501
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "CHAR", "INT", "FLOAT",
  "LET", "DEC", "STR_TYPE", "CHR_TYPE", "BUL_TYPE", "NUL_TYPE", "CLS",
  "ENM", "TYP", "CON", "IF_COLON", "ELIF_COLON", "WHILE_COLON", "DO",
  "ELSE", "BRK", "CNT", "RET", "OUT", "INP", "AND", "OR", "NOT",
  "MAIN_FUNC", "LET_PTR", "PRINT_SLICE", "FREE_SLICE", "GCD_FUNC",
  "ISPRIME_FUNC", "FACTORIAL_FUNC", "ISPALINDROME_FUNC", "SUM_FUNC",
  "MAX_FUNC", "MIN_FUNC", "AVG_FUNC", "SWAP_FUNC", "POW_EXPR", "POW_OP",
  "GE", "LE", "EQ", "NE", "INC", "DECR", "PLUS", "MINUS", "MUL", "DIV",
  "MOD", "ASSIGN", "LT", "GT", "BITAND", "BITOR", "BITXOR", "BITNOT",
  "LSHIFT", "RSHIFT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMI",
  "COMMA", "COLON", "LBRACKET", "RBRACKET", "DOT", "$accept", "program",
  "$@1", "statement_list", "statement", "declaration", "type_specifier",
  "expression_statement", "compound_statement", "if_statement",
  "while_statement", "do_while_statement", "jump_statement", "expression",
  "assignment_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "primary_expression", "argument_list", 0
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
       0,    76,    78,    77,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    84,    85,
      85,    85,    86,    87,    88,    88,    88,    88,    89,    90,
      90,    91,    91,    92,    92,    93,    93,    93,    94,    94,
      94,    94,    94,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     9,     6,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     5,
       9,    10,     5,     7,     3,     2,     2,     2,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     2,     2,     1,     4,     3,     4,
       2,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     4,     0,    85,    88,    89,
      86,    87,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     3,    26,     5,
       6,     0,     7,     8,     9,    10,    11,    12,     0,    38,
      39,    41,    43,    45,    48,    53,    56,    60,    66,     0,
       0,     4,    36,    37,    35,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    62,    64,    65,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,     0,     0,     4,     4,     0,
      34,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    28,     0,    13,
       0,    42,    56,    44,    46,    47,    52,    51,    49,    50,
      54,    55,    57,    58,    59,    40,    68,     0,     0,     0,
       0,     0,    72,     0,    73,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
      69,    67,    29,    32,     0,    92,    17,    14,     0,     0,
       0,     0,     0,    16,     0,     0,     4,    33,     0,     4,
       0,     0,     0,    30,    15,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     5,     6,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   121,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int16 yypact[] =
{
     -13,   -67,     5,   -68,   -68,   -68,   194,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     695,   695,     8,   -39,     3,    61,    20,    23,   695,   102,
      40,    42,    43,    49,    50,    51,    53,    54,    56,    57,
      58,   695,   695,   695,   695,   695,   -68,   -68,   -68,   -68,
     -68,   104,   -68,   -68,   -68,   -68,   -68,   -68,    55,   -68,
      97,   101,     2,   -21,     6,     7,    73,   -38,   -68,    65,
      66,   -68,   -68,   -68,   -68,    67,   695,   695,   -68,    78,
     695,   695,   695,   695,   695,   695,   695,   695,   695,   695,
     695,   -68,   -68,   -68,   -68,    69,   262,   -40,   -68,   695,
     695,   695,   695,   695,   695,   695,   695,   695,   695,   695,
     695,   695,   695,   -68,   -68,   653,   695,   -68,   -68,   330,
     -68,   -68,   -64,   -63,   695,    71,    72,   -61,    88,    89,
      91,   -35,   -27,   -26,   -25,   -24,   -68,   -68,   695,   -68,
      -4,   101,   -68,     2,   -21,   -21,     6,     6,     6,     6,
       7,     7,   -68,   -68,   -68,   -68,   -68,   -19,    86,   398,
     466,   141,   -68,   695,   -68,    93,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,    94,    92,   108,
     -68,   -68,    38,   -68,   695,   -68,   -68,   -68,    98,    99,
     695,   103,   100,   -68,   695,   105,   -68,   -68,   -42,   -68,
     534,   106,   602,   -68,   -68,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -68,   -37,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,    -6,    60,   -68,    70,    74,   -30,   -50,
     -15,    41,   -68,   -68,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      58,     3,   178,   162,   164,     4,   168,   163,   163,    96,
     163,   123,   113,   114,    69,    70,   127,   138,     1,    75,
     131,   132,   133,   134,   135,   103,   104,   201,   115,   163,
     139,    72,   172,   140,   119,   116,   163,   105,   106,    95,
     173,   174,   175,   176,   163,   163,   163,   163,   180,   157,
     101,   102,   163,   146,   147,   148,   149,   190,   107,   108,
     191,   109,   110,   111,     7,     8,     9,    10,    11,    78,
     179,   144,   145,    73,   125,   126,    71,   128,   129,   130,
     159,   160,    91,    92,    93,    94,    76,    26,    27,    77,
      58,    28,   150,   151,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    79,    80,    97,    81,    82,
     158,    41,    42,    58,    43,    83,    84,    85,   165,    86,
      87,    44,    88,    89,    90,    98,    99,    45,   198,   100,
     112,    74,   177,   117,   118,   124,   136,   120,   166,   167,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     152,   153,   154,    58,    58,   169,   170,   185,   171,   200,
     181,   184,   202,   186,   187,   189,   188,   194,   193,   141,
     197,   196,   155,   199,   143,     0,   204,     0,   192,     0,
       0,     0,     0,     0,   195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,    58,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,    20,     0,    21,    22,     0,    23,    24,    25,
      26,    27,     0,     0,    28,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     0,
       0,     0,     0,     0,    41,    42,     0,    43,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
      45,     0,    46,    47,    48,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
      20,     0,    21,    22,     0,    23,    24,    25,    26,    27,
       0,     0,    28,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,    41,    42,     0,    43,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    45,     0,
      46,   137,    48,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,     0,    20,     0,
      21,    22,     0,    23,    24,    25,    26,    27,     0,     0,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     0,     0,     0,     0,
      41,    42,     0,    43,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    45,     0,    46,   161,
      48,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,     0,    20,     0,    21,    22,
       0,    23,    24,    25,    26,    27,     0,     0,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    45,     0,    46,   182,    48,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,    20,     0,    21,    22,     0,    23,
      24,    25,    26,    27,     0,     0,    28,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,    45,     0,    46,   183,    48,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,    20,     0,    21,    22,     0,    23,    24,    25,
      26,    27,     0,     0,    28,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     0,
       0,     0,     0,     0,    41,    42,     0,    43,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
      45,     0,    46,   203,    48,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
      20,     0,    21,    22,     0,    23,    24,    25,    26,    27,
       0,     0,    28,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,    41,    42,     0,    43,     7,     8,     9,    10,
      11,     0,    44,     0,     0,     0,     0,     0,    45,     0,
      46,   205,    48,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,    28,     0,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,     7,     8,
       9,    10,    11,    41,    42,     0,    43,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,    45,
     156,    26,    27,     0,     0,    28,     0,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,    41,    42,     0,    43,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,    45
};

static const yytype_int16 yycheck[] =
{
       6,    68,     6,    67,    67,     0,    67,    71,    71,    46,
      71,    77,    50,    51,    20,    21,    82,    57,    31,    25,
      86,    87,    88,    89,    90,    46,    47,    69,    66,    71,
      70,    70,    67,    73,    71,    73,    71,    58,    59,    45,
      67,    67,    67,    67,    71,    71,    71,    71,    67,   115,
      48,    49,    71,   103,   104,   105,   106,    19,    52,    53,
      22,    54,    55,    56,     3,     4,     5,     6,     7,    28,
      74,   101,   102,    70,    80,    81,    68,    83,    84,    85,
     117,   118,    41,    42,    43,    44,    66,    26,    27,    66,
      96,    30,   107,   108,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     3,    66,     3,    66,    66,
     116,    50,    51,   119,    53,    66,    66,    66,   124,    66,
      66,    60,    66,    66,    66,    70,    29,    66,   194,    28,
      57,    70,   138,    68,    68,    57,    67,    70,    67,    67,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   159,   160,    67,    67,   163,    67,   196,
      74,    20,   199,    70,    70,    57,    74,    68,    70,    99,
      70,    68,   112,    68,   100,    -1,    70,    -1,   184,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,    -1,   202,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    23,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    68,    69,    70,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      68,    69,    70,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    -1,
      20,    21,    -1,    23,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,
      70,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    23,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,    23,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    68,    69,    70,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    23,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    68,    69,    70,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    53,     3,     4,     5,     6,
       7,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,     3,     4,
       5,     6,     7,    50,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    77,    68,     0,    78,    79,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      18,    20,    21,    23,    24,    25,    26,    27,    30,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    50,    51,    53,    60,    66,    68,    69,    70,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    89,
      89,    68,    70,    70,    70,    89,    66,    66,    97,     3,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    97,    97,    97,    97,    89,    79,     3,    70,    29,
      28,    48,    49,    46,    47,    58,    59,    52,    53,    54,
      55,    56,    57,    50,    51,    66,    73,    68,    68,    79,
      70,    89,   100,   100,    57,    89,    89,   100,    89,    89,
      89,   100,   100,   100,   100,   100,    67,    69,    57,    70,
      73,    92,    97,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    97,    97,    97,    90,    67,   100,    89,    79,
      79,    69,    67,    71,    67,    89,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    89,     6,    74,
      67,    74,    69,    69,    20,    89,    70,    70,    74,    57,
      19,    22,    89,    70,    68,    89,    68,    70,   100,    68,
      79,    69,    79,    69,    70,    69
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
#line 88 "cmm_parser.y"
    {
        fprintf(output_file, "int main() {\n");
        if (global_arr_length > 0) {
            fprintf(output_file, "    int arr_length = %d;\n", global_arr_length);
        }
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 93 "cmm_parser.y"
    {
        fprintf(output_file, "}\n");
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 114 "cmm_parser.y"
    {
        fprintf(output_file, "    %s %s;\n", (yyvsp[(1) - (3)].sval), (yyvsp[(2) - (3)].sval));
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 118 "cmm_parser.y"
    {
        fprintf(output_file, "    %s %s = %s;\n", (yyvsp[(1) - (5)].sval), (yyvsp[(2) - (5)].sval), (yyvsp[(4) - (5)].sval));
        free((yyvsp[(1) - (5)].sval)); free((yyvsp[(2) - (5)].sval)); free((yyvsp[(4) - (5)].sval));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 122 "cmm_parser.y"
    {
        fprintf(output_file, "    %s %s[] = {%s};\n", (yyvsp[(1) - (9)].sval), (yyvsp[(2) - (9)].sval), (yyvsp[(7) - (9)].sval));
        free((yyvsp[(1) - (9)].sval)); free((yyvsp[(2) - (9)].sval)); free((yyvsp[(7) - (9)].sval));
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 126 "cmm_parser.y"
    {
        fprintf(output_file, "    %s %s[%d];\n", (yyvsp[(1) - (6)].sval), (yyvsp[(2) - (6)].sval), (yyvsp[(4) - (6)].ival));
        free((yyvsp[(1) - (6)].sval)); free((yyvsp[(2) - (6)].sval));
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 130 "cmm_parser.y"
    {
        fprintf(output_file, "    int* %s = %s;\n", (yyvsp[(2) - (5)].sval), (yyvsp[(4) - (5)].sval));
        free((yyvsp[(2) - (5)].sval)); free((yyvsp[(4) - (5)].sval));
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 137 "cmm_parser.y"
    { (yyval.sval) = strdup("int"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 138 "cmm_parser.y"
    { (yyval.sval) = strdup("double"); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 139 "cmm_parser.y"
    { (yyval.sval) = strdup("const char*"); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 140 "cmm_parser.y"
    { (yyval.sval) = strdup("char"); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 141 "cmm_parser.y"
    { (yyval.sval) = strdup("bool"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 142 "cmm_parser.y"
    { (yyval.sval) = strdup("void"); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 143 "cmm_parser.y"
    { (yyval.sval) = strdup("struct"); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 144 "cmm_parser.y"
    { (yyval.sval) = strdup("enum"); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 149 "cmm_parser.y"
    {
        fprintf(output_file, "    %s;\n", (yyvsp[(1) - (2)].sval));
        free((yyvsp[(1) - (2)].sval));
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 160 "cmm_parser.y"
    {
        fprintf(output_file, "    if (%s) {\n", (yyvsp[(2) - (5)].sval));
        fprintf(output_file, "    }\n");
        free((yyvsp[(2) - (5)].sval));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 165 "cmm_parser.y"
    {
        fprintf(output_file, "    if (%s) {\n", (yyvsp[(2) - (9)].sval));
        fprintf(output_file, "    } else {\n");
        fprintf(output_file, "    }\n");
        free((yyvsp[(2) - (9)].sval));
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 171 "cmm_parser.y"
    {
        fprintf(output_file, "    if (%s) {\n", (yyvsp[(2) - (10)].sval));
        fprintf(output_file, "    } else if (%s) {\n", (yyvsp[(7) - (10)].sval));
        fprintf(output_file, "    }\n");
        free((yyvsp[(2) - (10)].sval));
        free((yyvsp[(7) - (10)].sval));
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 181 "cmm_parser.y"
    {
        fprintf(output_file, "    while (%s) {\n", (yyvsp[(2) - (5)].sval));
        fprintf(output_file, "    }\n");
        free((yyvsp[(2) - (5)].sval));
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 189 "cmm_parser.y"
    {
        fprintf(output_file, "    do {\n");
        fprintf(output_file, "    } while (%s);\n", (yyvsp[(6) - (7)].sval));
        free((yyvsp[(6) - (7)].sval));
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 197 "cmm_parser.y"
    {
        fprintf(output_file, "    return %s;\n", (yyvsp[(2) - (3)].sval));
        free((yyvsp[(2) - (3)].sval));
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 201 "cmm_parser.y"
    {
        fprintf(output_file, "    return;\n");
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 204 "cmm_parser.y"
    {
        fprintf(output_file, "    break;\n");
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 207 "cmm_parser.y"
    {
        fprintf(output_file, "    continue;\n");
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 213 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 217 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 218 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s = %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 227 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 228 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s || %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 237 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 238 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s && %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 247 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 248 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s == %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 254 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s != %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 263 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 264 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s < %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 270 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s > %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 276 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s <= %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 282 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s >= %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 291 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 292 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s + %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 298 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s - %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 307 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 308 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s * %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 314 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s / %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 320 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s %% %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 329 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 330 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "++%s", (yyvsp[(2) - (2)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 336 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "--%s", (yyvsp[(2) - (2)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 342 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "!%s", (yyvsp[(2) - (2)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 348 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "-%s", (yyvsp[(2) - (2)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 354 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "&%s", (yyvsp[(2) - (2)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 363 "cmm_parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 364 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s[%s]", (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 370 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s()", (yyvsp[(1) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 376 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s(%s)", (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 382 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s++", (yyvsp[(1) - (2)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (2)].sval));
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 388 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "%s--", (yyvsp[(1) - (2)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (2)].sval));
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 394 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "printf(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 400 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "scanf(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 406 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "print_int_slice(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 412 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "free_int_slice(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 418 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "gcd(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 424 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "isprime(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 430 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "factorial(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 436 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "ispalindrome(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 442 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "sum(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 448 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "max(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 454 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "min(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 460 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "avg(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 466 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "swap(%s)", (yyvsp[(3) - (4)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 475 "cmm_parser.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 476 "cmm_parser.y"
    {
        char buf[64];
        snprintf(buf, sizeof(buf), "%d", (yyvsp[(1) - (1)].ival));
        (yyval.sval) = strdup(buf);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 481 "cmm_parser.y"
    {
        char buf[64];
        snprintf(buf, sizeof(buf), "%f", (yyvsp[(1) - (1)].fval));
        (yyval.sval) = strdup(buf);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 486 "cmm_parser.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 487 "cmm_parser.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 488 "cmm_parser.y"
    {
        char buf[512];
        snprintf(buf, sizeof(buf), "(%s)", (yyvsp[(2) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(2) - (3)].sval));
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 497 "cmm_parser.y"
    {
        (yyval.sval) = strdup((yyvsp[(1) - (1)].sval));
        free((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 501 "cmm_parser.y"
    {
        char buf[1024];
        snprintf(buf, sizeof(buf), "%s, %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        (yyval.sval) = strdup(buf);
        free((yyvsp[(1) - (3)].sval)); free((yyvsp[(3) - (3)].sval));
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2544 "cmm_parser.tab.c"
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
#line 509 "cmm_parser.y"


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
