/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 22 "parser.yacc" /* yacc.c:1909  */

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

#line 184 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
