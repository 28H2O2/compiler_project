/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parser.yacc" /* yacc.c:339  */

#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(const char *s); 
extern int  yywrap();
}


#line 81 "y.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    AND = 262,
    OR = 263,
    NOT = 264,
    LP = 265,
    RP = 266,
    LB = 267,
    RB = 268,
    LC = 269,
    RC = 270,
    GT = 271,
    LT = 272,
    GTEQ = 273,
    LTEQ = 274,
    EQ = 275,
    NEQ = 276,
    SEMICOLON = 277,
    COMMA = 278,
    ASSIGN = 279,
    RETURN = 280,
    IF = 281,
    ELSE = 282,
    WHILE = 283,
    BREAK = 284,
    CONTINUE = 285,
    INT = 286,
    FN = 287,
    LET = 288,
    STRUCT = 289,
    ARROW = 290,
    DOT = 291,
    COLON = 292,
    NUM = 293,
    ID = 294,
    NEG = 295,
    LOWER_THAN_LP = 296
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define AND 262
#define OR 263
#define NOT 264
#define LP 265
#define RP 266
#define LB 267
#define RB 268
#define LC 269
#define RC 270
#define GT 271
#define LT 272
#define GTEQ 273
#define LTEQ 274
#define EQ 275
#define NEQ 276
#define SEMICOLON 277
#define COMMA 278
#define ASSIGN 279
#define RETURN 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define BREAK 284
#define CONTINUE 285
#define INT 286
#define FN 287
#define LET 288
#define STRUCT 289
#define ARROW 290
#define DOT 291
#define COLON 292
#define NUM 293
#define ID 294
#define NEG 295
#define LOWER_THAN_LP 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "parser.yacc" /* yacc.c:355  */

  A_pos pos;  // 位置信息
  A_type type;
  A_varDecl varDecl;
  A_varDef varDef;
  A_rightVal rightVal;
  A_arithExpr arithExpr;
  A_boolExpr boolExpr;
  A_arithBiOpExpr arithBiOpExpr;
  A_arithUExpr arithUExpr;
  A_exprUnit exprUnit;
  A_fnCall fnCall;
  A_indexExpr indexExpr;
  A_arrayExpr arrayExpr;
  A_memberExpr memberExpr;
  A_boolUnit boolUnit;
  A_boolBiOpExpr boolBiOpExpr;
  A_boolUOpExpr boolUOpExpr;
  A_comExpr comExpr;
  A_leftVal leftVal;
  A_assignStmt assignStmt;
  A_rightValList rightValList;
  A_varDefScalar varDefScalar;
  A_varDefArray varDefArray;
  A_varDeclScalar varDeclScalar;
  A_varDeclArray varDeclArray;
  A_varDeclStmt varDeclStmt;
  A_varDeclList varDeclList;
  A_structDef structDef;
  A_paramDecl paramDecl;
  A_fnDecl fnDecl;
  A_fnDef fnDef;
  A_codeBlockStmt codeBlockStmt;
  A_ifStmt ifStmt;
  A_whileStmt whileStmt;
  A_fnDeclStmt fnDeclStmt;
  A_callStmt callStmt;
  A_returnStmt returnStmt;
  A_programElement programElement;
  A_codeBlockStmtList codeBlockStmtList;
  A_programElementList programElementList;
  A_program program;
  A_tokenId tokenId;  // 标识符
  A_tokenNum tokenNum; // 数字
  // A_fieldDecl fieldDecl;
  // A_fieldDeclList fieldDeclList;

#line 251 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 268 "y.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   156,   156,   163,   168,   174,   178,   182,   186,   190,
     197,   201,   205,   209,   213,   220,   224,   228,   232,   236,
     240,   244,   269,   273,   277,   281,   288,   292,   299,   307,
     311,   317,   321,   325,   329,   333,   337,   370,   374,   378,
     384,   391,   395,   402,   408,   412,   416,   422,   429,   433,
     439,   443,   449,   453,   459,   463,   467,   473,   477,   481,
     485,   489,   493,   499,   503,   510,   514,   520,   526,   530,
     537,   543,   547,   553,   558,   564,   570,   573,   579,   583,
     589,   593,   597,   601,   605,   609,   613,   617,   621,   627,
     631,   637,   643,   649,   656,   660,   680
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "AND", "OR",
  "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "GT", "LT", "GTEQ", "LTEQ",
  "EQ", "NEQ", "SEMICOLON", "COMMA", "ASSIGN", "RETURN", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "INT", "FN", "LET", "STRUCT", "ARROW",
  "DOT", "COLON", "NUM", "ID", "NEG", "LOWER_THAN_LP", "$accept",
  "Program", "ProgramElementList", "ProgramElement", "ArithExpr",
  "ExprUnit", "ArrayExpr", "MemberExpr", "ArithUExpr", "BoolBiOpExpr",
  "ComExpr", "BoolUnit", "BoolUOpExpr", "BoolExpr", "AssignStmt",
  "LeftVal", "RightVal", "FnCall", "RightValList", "VarDeclStmt",
  "VarDecl", "VarDef", "Type", "FieldDecl", "StructDef", "FieldDeclList",
  "FnDeclStmt", "FnDecl", "ParamDecl", "FnDef", "CodeBlock",
  "CodeBlockStmtList", "CodeBlockStmt", "ReturnStmt", "ContinueStmt",
  "BreakStmt", "CallStmt", "IfStmt", "WhileStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -86

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-86)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     107,   -86,   -22,   -16,    22,    32,   -86,   107,   -86,   -86,
     -86,    19,   -86,    73,    58,    74,   -86,    28,    77,    83,
      79,   -86,   -86,    93,   -86,   -86,    70,    -9,    10,    86,
      71,   114,    71,    75,    98,   -86,   -86,    70,   -86,   -86,
       5,   155,   155,   144,   145,    61,   -86,   -86,   100,   147,
     -86,   156,   105,   -86,   -86,   -86,   -86,   -86,   -86,    80,
     131,   149,   -86,   159,   160,   161,    10,    10,   -86,    61,
     146,   -86,    67,    84,   -86,   -86,   -86,   -86,   -86,   -86,
     151,    24,   152,   164,   165,   -86,   166,   -86,   157,    68,
     168,   -86,   168,   -86,   -86,    27,    10,   -86,   -86,   -86,
      71,    71,    70,   148,   -86,   -86,   -86,   142,    10,    10,
      10,    10,    10,   -86,   162,   169,   172,   -86,   -86,   -86,
     -86,   155,    68,   138,   -86,   176,   -86,   153,   163,   -86,
     -86,   177,   158,   -86,   -86,   -86,    71,   -86,   137,   137,
     -86,   -86,   -86,    10,   -86,    42,   178,   138,    10,    10,
      10,    10,    10,    10,   -86,   155,   155,   -86,   168,   -86,
     -86,   -86,   -86,   -86,   179,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   184,   -86,   -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     9,     0,     0,     0,     0,     2,     4,     5,     6,
       7,     0,     8,     0,    56,    45,    46,     0,     0,     0,
       0,     1,     3,     0,    70,    75,    74,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,    76,    80,
       0,     0,     0,     0,     0,    44,    45,    82,     0,     0,
      81,     0,    79,    86,    87,    88,    83,    84,    85,     0,
      45,    68,    73,     0,     0,     0,     0,     0,    15,    16,
      47,    14,    19,    20,    21,    58,    18,    27,    63,    64,
      54,     0,    55,     0,     0,    26,     0,    90,     0,     0,
       0,    39,     0,    92,    91,     0,     0,    93,    77,    78,
       0,     0,     0,    71,    22,    23,    28,     0,     0,     0,
       0,     0,     0,    62,    50,     0,     0,    24,    25,    67,
      89,     0,     0,     0,    41,     0,    42,     0,    95,    96,
      49,     0,     0,    65,    66,    69,     0,    17,    10,    11,
      12,    13,    57,     0,    60,     0,     0,    14,     0,     0,
       0,     0,     0,     0,    37,     0,     0,    38,     0,    48,
      43,    72,    51,    61,     0,    40,    33,    31,    34,    32,
      35,    36,    29,    30,    94,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,   185,   -86,   -55,   -63,    -2,    -1,   -86,   -86,
     -86,   -37,   -86,     7,   -86,   -10,   -21,    -7,   -85,    -5,
     -86,   -86,   -32,   -86,   -86,   -26,   -86,   -86,   -86,   -86,
     -84,   141,   -86,   -86,   -86,   -86,   -86,   -86,   -86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    70,    71,    72,    73,    74,   124,
     125,   126,    91,   127,    47,    17,   114,    76,   115,     8,
      18,    19,    80,    61,     9,    62,    10,    11,    63,    12,
      25,    51,    52,    53,    54,    55,    56,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,    15,    16,   106,    90,    92,   128,    75,   129,    66,
     131,    86,   107,    48,    66,    67,    49,    13,    50,    88,
      67,    46,    16,    14,    60,    16,   123,    87,    66,    64,
      65,    66,    21,    23,    67,    60,    16,    67,   130,   113,
      33,    24,    48,    68,    69,    49,    66,    50,    68,    69,
      46,    16,    67,   138,   139,   140,   141,   163,   162,   147,
     164,    20,    68,    69,    34,    68,    69,   107,   133,   134,
      27,    95,    66,    27,   174,   132,   135,   121,   122,   -45,
      68,    69,    28,    26,   146,   166,   167,   168,   169,   170,
     171,   142,    27,    37,    29,    30,   -46,    29,    31,    35,
      60,    16,    78,   -45,   161,    36,    68,    69,    38,    59,
      79,    32,    33,    83,    84,    39,    29,   100,    40,    41,
     -46,    42,    43,    44,    96,    77,     3,    39,    81,     1,
      40,    41,    45,    42,    43,    44,    34,    85,     3,     2,
       3,     4,   110,   111,    45,   108,   109,   110,   111,   108,
     109,   110,   111,   137,   148,   149,   150,   151,   152,   153,
     155,   156,   172,   173,   157,    89,    93,    94,   101,    97,
     103,    98,   102,   104,   105,   112,   116,   117,   118,   120,
     160,   119,    23,   136,   144,   143,   145,   154,   159,   165,
     158,   155,    22,    99,   175
};

static const yytype_uint8 yycheck[] =
{
      32,     3,     3,    66,    41,    42,    90,    28,    92,     4,
      95,    37,    67,    23,     4,    10,    23,    39,    23,    40,
      10,    23,    23,    39,    26,    26,    89,    22,     4,    38,
      39,     4,     0,    14,    10,    37,    37,    10,    11,    15,
      12,    22,    52,    38,    39,    52,     4,    52,    38,    39,
      52,    52,    10,   108,   109,   110,   111,    15,   143,   122,
     145,    39,    38,    39,    36,    38,    39,   122,   100,   101,
      12,    10,     4,    12,   158,    96,   102,     9,    10,    12,
      38,    39,    24,    10,   121,   148,   149,   150,   151,   152,
     153,   112,    12,    14,    36,    37,    12,    36,    24,    22,
     102,   102,    31,    36,   136,    22,    38,    39,    15,    39,
      39,    37,    12,    38,    39,    22,    36,    37,    25,    26,
      36,    28,    29,    30,    24,    39,    33,    22,    14,    22,
      25,    26,    39,    28,    29,    30,    36,    39,    33,    32,
      33,    34,     5,     6,    39,     3,     4,     5,     6,     3,
       4,     5,     6,    11,    16,    17,    18,    19,    20,    21,
       7,     8,   155,   156,    11,    10,    22,    22,    37,    22,
      11,    15,    23,    13,    13,    24,    24,    13,    13,    22,
      22,    15,    14,    35,    15,    23,    14,    11,    11,    11,
      27,     7,     7,    52,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    32,    33,    34,    43,    44,    45,    61,    66,
      68,    69,    71,    39,    39,    48,    49,    57,    62,    63,
      39,     0,    44,    14,    22,    72,    10,    12,    24,    36,
      37,    24,    37,    12,    36,    22,    22,    14,    15,    22,
      25,    26,    28,    29,    30,    39,    48,    56,    57,    59,
      61,    73,    74,    75,    76,    77,    78,    79,    80,    39,
      48,    65,    67,    70,    38,    39,     4,    10,    38,    39,
      46,    47,    48,    49,    50,    58,    59,    39,    31,    39,
      64,    14,    64,    38,    39,    39,    67,    22,    58,    10,
      53,    54,    53,    22,    22,    10,    24,    22,    15,    73,
      37,    37,    23,    11,    13,    13,    47,    46,     3,     4,
       5,     6,    24,    15,    58,    60,    24,    13,    13,    15,
      22,     9,    10,    47,    51,    52,    53,    55,    72,    72,
      11,    60,    58,    64,    64,    67,    35,    11,    46,    46,
      46,    46,    58,    23,    15,    14,    53,    47,    16,    17,
      18,    19,    20,    21,    11,     7,     8,    11,    27,    11,
      22,    64,    60,    15,    60,    11,    47,    47,    47,    47,
      47,    47,    55,    55,    72,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      46,    46,    46,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    53,    53,    53,
      54,    55,    55,    56,    57,    57,    57,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    69,    69,    70,    70,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    77,    78,    79,    79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     4,     4,     4,     4,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       4,     1,     1,     4,     1,     1,     1,     1,     4,     3,
       1,     3,     3,     3,     3,     3,     1,     5,     3,     7,
       5,     6,     4,     1,     1,     3,     3,     5,     1,     3,
       2,     5,     7,     1,     0,     2,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     2,     2,     5,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 157 "parser.yacc" /* yacc.c:1646  */
    {  
  root = A_Program((yyvsp[0].programElementList));  // 将根节点设置为ProgramElementList
  (yyval.program) = A_Program((yyvsp[0].programElementList));   // 将当前节点设置为ProgramElementList
}
#line 1477 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 164 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));  // 将当前节点设置为ProgramElementList
}
#line 1485 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 168 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.programElementList) = nullptr;
}
#line 1493 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 175 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1501 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 179 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 1509 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 183 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 1517 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 187 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 1525 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 191 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
}
#line 1533 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 198 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1541 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 202 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1549 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 206 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1557 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 210 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1565 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 214 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
}
#line 1573 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 221 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 1581 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 225 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1589 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 229 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-2].pos), (yyvsp[-1].arithExpr));
}
#line 1597 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 233 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
}
#line 1605 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 237 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1613 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 241 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.exprUnit) = A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1621 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 245 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.exprUnit) = (yyvsp[0].exprUnit);
}
#line 1629 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 270 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].tokenId)->pos, A_IdExprLVal((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1637 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 274 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].tokenId)->pos, A_IdExprLVal((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1645 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 278 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1653 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 282 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1661 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 289 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id);
}
#line 1669 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 293 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].tokenId)->pos, A_IdExprLVal((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id), (yyvsp[0].tokenId)->id);
}
#line 1677 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 300 "parser.yacc" /* yacc.c:1646  */
    {
  // $$ = A_ArithUExpr($1, A_neg, $2);
  (yyval.exprUnit) = A_NumExprUnit((yyvsp[-1].pos), -((yyvsp[0].exprUnit)->u.num));
}
#line 1686 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 308 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_and, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 1694 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 312 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_or, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 1702 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 318 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_lt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1710 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 322 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_le, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1718 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 326 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_gt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1726 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 330 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ge, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1734 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 334 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_eq, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1742 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 338 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ne, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1750 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 371 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-1].comExpr)->pos, (yyvsp[-1].comExpr));
}
#line 1758 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 375 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1766 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 379 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[0].boolUOpExpr)->pos, (yyvsp[0].boolUOpExpr));
}
#line 1774 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 385 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.boolUOpExpr) = A_BoolUOpExpr((yyvsp[-3].pos), A_not, (yyvsp[-1].boolUnit));
}
#line 1782 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 392 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[0].boolBiOpExpr)->pos, (yyvsp[0].boolBiOpExpr));
}
#line 1790 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
}
#line 1798 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 403 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
}
#line 1806 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 409 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1814 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 413 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1822 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 417 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.leftVal) = A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1830 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 423 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
}
#line 1838 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 430 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
}
#line 1846 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 434 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.fnCall) = A_FnCall((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr);
}
#line 1854 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 440 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.rightValList) = A_RightValList((yyvsp[0].rightVal), nullptr);
}
#line 1862 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 444 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.rightValList) = A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
}
#line 1870 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 450 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-2].pos), (yyvsp[-1].varDecl));
}
#line 1878 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 454 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-2].pos), (yyvsp[-1].varDef));
}
#line 1886 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 460 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[-2].tokenId)->pos, A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type)));
}
#line 1894 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 464 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[-2].arrayExpr)->pos, A_VarDeclArray((yyvsp[-2].arrayExpr)->pos, (yyvsp[-2].arrayExpr)->arr->u.id, (yyvsp[-2].arrayExpr)->idx->u.num, (yyvsp[0].type)));
}
#line 1902 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 468 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].tokenId)->pos, A_VarDeclScalar((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id, nullptr));
}
#line 1910 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 474 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[-4].tokenId)->pos, A_VarDefScalar((yyvsp[-4].tokenId)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal)));
}
#line 1918 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 478 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[-2].tokenId)->pos, A_VarDefScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr, (yyvsp[0].rightVal)));
}
#line 1926 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 482 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.varDef) = A_VarDef_Array((yyvsp[-6].arrayExpr)->pos, A_VarDefArray((yyvsp[-6].arrayExpr)->pos, (yyvsp[-6].arrayExpr)->arr->u.id, (yyvsp[-6].arrayExpr)->idx->u.num, (yyvsp[-4].type), (yyvsp[-1].rightValList)));
}
#line 1934 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 486 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.varDef) = A_VarDef_Array((yyvsp[-4].arrayExpr)->pos, A_VarDefArray((yyvsp[-4].arrayExpr)->pos, (yyvsp[-4].arrayExpr)->arr->u.id, (yyvsp[-4].arrayExpr)->idx->u.num, nullptr, (yyvsp[-1].rightValList)));
}
#line 1942 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 490 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.varDef) = A_VarDef_Array((yyvsp[-5].arrayExpr)->pos, A_VarDefArray((yyvsp[-5].arrayExpr)->pos, (yyvsp[-5].arrayExpr)->arr->u.id, (yyvsp[-5].arrayExpr)->idx->u.num, (yyvsp[-3].type), nullptr));
}
#line 1950 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 494 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.varDef) = A_VarDef_Array((yyvsp[-3].arrayExpr)->pos, A_VarDefArray((yyvsp[-3].arrayExpr)->pos, (yyvsp[-3].arrayExpr)->arr->u.id, (yyvsp[-3].arrayExpr)->idx->u.num, nullptr, nullptr));
}
#line 1958 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 500 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.type) = A_NativeType((yyvsp[0].pos), A_intTypeKind);
}
#line 1966 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 504 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1974 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 511 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[-2].tokenId)->pos, A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type)));
}
#line 1982 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 515 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[-2].arrayExpr)->pos, A_VarDeclArray((yyvsp[-2].arrayExpr)->pos, (yyvsp[-2].arrayExpr)->arr->u.id, (yyvsp[-2].arrayExpr)->idx->u.num, (yyvsp[0].type)));
}
#line 1990 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 521 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.structDef) = A_StructDef((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
}
#line 1998 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 527 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), nullptr);
}
#line 2006 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 531 "parser.yacc" /* yacc.c:1646  */
    {
  (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
}
#line 2014 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 538 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
}
#line 2022 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 544 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), nullptr);
}
#line 2030 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 548 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
}
#line 2038 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 554 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
}
#line 2046 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 558 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.paramDecl) = A_ParamDecl(nullptr);
}
#line 2054 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 565 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.fnDef) = A_FnDef((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl), (yyvsp[0].codeBlockStmtList));
}
#line 2062 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 570 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmtList) = nullptr;
}
#line 2070 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 574 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmtList) = (yyvsp[-1].codeBlockStmtList);
}
#line 2078 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 580 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
}
#line 2086 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 584 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[0].codeBlockStmt), nullptr);
}
#line 2094 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 590 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[0].pos));
}
#line 2102 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 594 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 2110 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 598 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
}
#line 2118 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 602 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
}
#line 2126 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 606 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
}
#line 2134 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 610 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
}
#line 2142 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 614 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
}
#line 2150 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 618 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[0].pos));
}
#line 2158 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 622 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[0].pos));
}
#line 2166 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 628 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos), (yyvsp[-1].rightVal));
}
#line 2174 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 632 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-1].pos), nullptr);
}
#line 2182 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 638 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.pos) = (yyvsp[-1].pos);
}
#line 2190 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 644 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.pos) = (yyvsp[-1].pos);
}
#line 2198 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 650 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
}
#line 2206 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 657 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.ifStmt) = A_IfStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-2].codeBlockStmtList), (yyvsp[0].codeBlockStmtList));
}
#line 2214 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 661 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.ifStmt) = A_IfStmt((yyvsp[-2].pos), (yyvsp[-1].boolUnit), (yyvsp[0].codeBlockStmtList), nullptr);
}
#line 2222 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 681 "parser.yacc" /* yacc.c:1646  */
    {
    (yyval.whileStmt) = A_WhileStmt((yyvsp[-2].pos), (yyvsp[-1].boolUnit), (yyvsp[0].codeBlockStmtList));
}
#line 2230 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2234 "y.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 686 "parser.yacc" /* yacc.c:1906  */

//  辅助函数

extern "C"{
void yyerror(const char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  return(1);
}
}


