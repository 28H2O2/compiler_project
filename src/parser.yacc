// 声明部分
%{
#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(const char *s); 
extern int  yywrap();
}

%}

// TODO:
// your parser

// 使用TeaplAst.h的结构
// 语法分析的每个单元（最后显示在语法树上的）
%union {
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
}

// token的类
// %token <name in union> token_name_1 token_name_2
// 都是终结符：不能再进一步替换的基本符号
%token <pos> ADD SUB MUL DIV // 算术运算符
%token <pos> AND OR NOT // 逻辑运算符
%token <pos> LP RP LB RB LC RC // 圆括号 方括号 花括号
%token <pos> GT LT GTEQ LTEQ EQ NEQ // 关系运算符
%token <pos> SEMICOLON COMMA// 分号和逗号
%token <pos> ASSIGN // 赋值运算符
%token <pos> RETURN // 返回运算符
%token <pos> IF ELSE WHILE // 条件语句
%token <pos> BREAK // break
%token <pos> CONTINUE // continue
%token <pos> INT // 整数类型
%token <pos> FN LET // 函数声明和变量声明
%token <pos> STRUCT // 结构体声明
%token <pos> ARROW DOT COLON // 箭头 点 冒号

%token <tokenNum> NUM // 数字
%token <tokenId> ID // 标识符

// 指定优先级和结合性，优先级自下而上
%left COMMA
%right ASSIGN
%left OR
%left AND 
%left EQ NEQ
%left LT GT LTEQ GTEQ
%left ADD SUB
%left MUL DIV
// nonassoc: 不结合
%nonassoc NEG  // 负号
%right NOT
%nonassoc LOWER_THAN_LP  // 小于左括号的优先级
%left LP RP LB RB DOT  // 左括号 右括号 左方括号 右方括号 点

// 非终结符的类
%type <program> Program
%type <arithExpr> ArithExpr
%type <programElementList> ProgramElementList
%type <programElement> ProgramElement
%type <exprUnit> ExprUnit
%type <structDef> StructDef
%type <varDeclStmt> VarDeclStmt
%type <fnDeclStmt> FnDeclStmt
%type <fnDef> FnDef
%type <boolBiOpExpr> BoolBiOpExpr
%type <boolExpr> BoolExpr
%type <boolUnit> BoolUnit
// %type <boolUnit> BoolUnit_
%type <comExpr> ComExpr
%type <rightVal> RightVal
%type <rightValList> RightValList
%type <assignStmt> AssignStmt
%type <fnCall> FnCall
%type <varDecl> FieldDecl
%type <varDeclList> FieldDeclList
%type <arrayExpr> ArrayExpr
%type <memberExpr> MemberExpr
%type <exprUnit> ArithUExpr
%type <leftVal> LeftVal
%type <varDecl> VarDecl
%type <varDef> VarDef
%type <type> Type
%type <paramDecl> ParamDecl
%type <fnDecl> FnDecl
%type <codeBlockStmt> CodeBlockStmt
%type <ifStmt> IfStmt
%type <whileStmt> WhileStmt
%type <callStmt> CallStmt
%type <returnStmt> ReturnStmt
%type <codeBlockStmtList> CodeBlockStmtList
%type <codeBlockStmtList> CodeBlock
%type <pos> ContinueStmt
%type <pos> BreakStmt
%type <boolUOpExpr> BoolUOpExpr

// 开始符号
%start Program

%%                   /* beginning of rules section */
// 语法规则部分
// $1: 第一个元素
// $2: 第二个元素
// $$: 当前结果

Program: ProgramElementList 
{  
  root = A_Program($1);  // 将根节点设置为ProgramElementList
  $$ = A_Program($1);   // 将当前节点设置为ProgramElementList
}
;

ProgramElementList: ProgramElement ProgramElementList
{
  $$ = A_ProgramElementList($1, $2);  // 将当前节点设置为ProgramElementList
}
|
{
  $$ = nullptr;
}
;

// 语法树的节点，和teapl.md中的语法规则一一对应
ProgramElement: VarDeclStmt  // 变量声明语句
{
  $$ = A_ProgramVarDeclStmt($1->pos, $1);
}
| StructDef
{
  $$ = A_ProgramStructDef($1->pos, $1);
}
| FnDeclStmt  // 函数声明语句
{
  $$ = A_ProgramFnDeclStmt($1->pos, $1);
}
| FnDef  // 函数定义
{
  $$ = A_ProgramFnDef($1->pos, $1);
}
| SEMICOLON  // 空语句
{
  $$ = A_ProgramNullStmt($1);
}
;

// 算术表达式
ArithExpr: ArithExpr ADD ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_add, $1, $3));
}
| ArithExpr SUB ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_sub, $1, $3));
}
| ArithExpr MUL ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_mul, $1, $3));
}
| ArithExpr DIV ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_div, $1, $3));
}
| ExprUnit
{
  $$ = A_ExprUnit($1->pos, $1);
}
;

// 表达式单元
ExprUnit: NUM
{
  $$ = A_NumExprUnit($1->pos, $1->num);
}
| ID
{
  $$ = A_IdExprUnit($1->pos, $1->id);
}
| LP ArithExpr RP
{
  $$ = A_ArithExprUnit($1, $2);
}
| FnCall
{
  $$ = A_CallExprUnit($1->pos, $1);
}
| ArrayExpr
{
  $$ = A_ArrayExprUnit($1->pos, $1);
}
| MemberExpr
{
  $$ = A_MemberExprUnit($1->pos, $1);
}
| ArithUExpr
{
  $$ = $1;
}
;

// ArithBiOp: ADD
// {
//   $$ = A_ArithBiOp($1->pos, A_add);
// }
// | SUB
// {
//   $$ = A_ArithBiOp($1->pos, A_sub);
// }
// | MUL
// {
//   $$ = A_ArithBiOp($1->pos, A_mul);
// }
// | DIV
// {
//   $$ = A_ArithBiOp($1->pos, A_div);
// }
// ;

// 数组下标表达式
ArrayExpr: ID LB NUM RB
{
    $$ = A_ArrayExpr($1->pos, A_IdExprLVal($1->pos, $1->id), A_NumIndexExpr($3->pos, $3->num));
}
| ID LB ID RB
{
    $$ = A_ArrayExpr($1->pos, A_IdExprLVal($1->pos, $1->id), A_IdIndexExpr($3->pos, $3->id));
}
| LeftVal LB NUM RB
{
    $$ = A_ArrayExpr($1->pos, $1, A_NumIndexExpr($3->pos, $3->num));
}
| LeftVal LB ID RB
{
    $$ = A_ArrayExpr($1->pos, $1, A_IdIndexExpr($3->pos, $3->id));
}
;

// 成员表达式
MemberExpr: LeftVal DOT ID
{
    $$ = A_MemberExpr($1->pos, $1, $3->id);
}
| ID DOT ID
{
    $$ = A_MemberExpr($1->pos, A_IdExprLVal($1->pos, $1->id), $3->id);
}
;

// 算术单元表达式
ArithUExpr: SUB ExprUnit %prec NEG
{
  // $$ = A_ArithUExpr($1, A_neg, $2);
  $$ = A_NumExprUnit($1, -($2->u.num));
}
;

// Condition Expressions
BoolBiOpExpr: BoolExpr AND BoolExpr
{
    $$ = A_BoolBiOpExpr($1->pos, A_and, $1, $3);
}
| BoolExpr OR BoolExpr
{
    $$ = A_BoolBiOpExpr($1->pos, A_or, $1, $3);
}
;

ComExpr: ExprUnit LT ExprUnit
{
  $$ = A_ComExpr($1->pos, A_lt, $1, $3);
}
| ExprUnit LTEQ ExprUnit
{
  $$ = A_ComExpr($1->pos, A_le, $1, $3);
}
| ExprUnit GT ExprUnit
{
  $$ = A_ComExpr($1->pos, A_gt, $1, $3);
}
| ExprUnit GTEQ ExprUnit
{
  $$ = A_ComExpr($1->pos, A_ge, $1, $3);
}
| ExprUnit EQ ExprUnit
{
  $$ = A_ComExpr($1->pos, A_eq, $1, $3);
}
| ExprUnit NEQ ExprUnit
{
  $$ = A_ComExpr($1->pos, A_ne, $1, $3);
};

// ComOp: LT
// {
//   $$ = A_ComOp($1->pos, A_lt);
// }
// | LTEQ
// {
//   $$ = A_ComOp($1->pos, A_le);
// }
// | GT
// {
//   $$ = A_ComOp($1->pos, A_gt);
// }
// | GTEQ
// {
//   $$ = A_ComOp($1->pos, A_ge);
// }
// | EQ
// {
//   $$ = A_ComOp($1->pos, A_eq);
// }
// | NEQ
// {
//   $$ = A_ComOp($1->pos, A_ne);
// }
// ;



BoolUnit: LP ComExpr RP
{
  $$ = A_ComExprUnit($2->pos, $2);
}
| LP BoolExpr RP
{
  $$ = A_BoolExprUnit($1, $2);
}
| BoolUOpExpr
{
  $$ = A_BoolUOpExprUnit($1->pos, $1);
}
;

BoolUOpExpr: LP NOT BoolUnit RP
{
  $$ = A_BoolUOpExpr($1, A_not, $3);
}
;


BoolExpr: BoolBiOpExpr
{
    $$ = A_BoolBiOp_Expr($1->pos, $1);
}
| BoolUnit
{
    $$ = A_BoolExpr($1->pos, $1);
}
;

// Assignment
AssignStmt: LeftVal ASSIGN RightVal SEMICOLON
{
  $$ = A_AssignStmt($1->pos, $1, $3);
}
;

LeftVal: ID %prec LOWER_THAN_LP  // 优先级低于左括号
{
  $$ = A_IdExprLVal($1->pos, $1->id);
}
| ArrayExpr
{
  $$ = A_ArrExprLVal($1->pos, $1);
}
| MemberExpr
{
  $$ = A_MemberExprLVal($1->pos, $1);
}
;

RightVal: ArithExpr
{
  $$ = A_ArithExprRVal($1->pos, $1);
}
;

// Function Call
FnCall: ID LP RightValList RP
{
  $$ = A_FnCall($1->pos, $1->id, $3);
}
| ID LP RP     // 上面的RightValList为空，ϵ表示无参数
{
    $$ = A_FnCall($1->pos, $1->id, nullptr);
}
;

RightValList: RightVal
{
  $$ = A_RightValList($1, nullptr);
}
| RightVal COMMA RightValList
{
  $$ = A_RightValList($1, $3);
}

// 变量声明语句
VarDeclStmt: LET VarDecl SEMICOLON
{
  $$ = A_VarDeclStmt($1, $2);
}
| LET VarDef SEMICOLON
{
  $$ = A_VarDefStmt($1, $2);
}
;

VarDecl: ID COLON Type
{
  $$ = A_VarDecl_Scalar($1->pos, A_VarDeclScalar($1->pos, $1->id, $3));
}
| ArrayExpr COLON Type
{
  $$ = A_VarDecl_Array($1->pos, A_VarDeclArray($1->pos, $1->arr->u.id, $1->idx->u.num, $3));
}
| ID
{
  $$ = A_VarDecl_Scalar($1->pos, A_VarDeclScalar($1->pos, $1->id, nullptr));
}
;

VarDef: ID COLON Type ASSIGN RightVal
{
    $$ = A_VarDef_Scalar($1->pos, A_VarDefScalar($1->pos, $1->id, $3, $5));
}
| ID ASSIGN RightVal
{
    $$ = A_VarDef_Scalar($1->pos, A_VarDefScalar($1->pos, $1->id, nullptr, $3));
}
| ArrayExpr COLON Type ASSIGN LC RightValList RC
{
    $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->arr->u.id, $1->idx->u.num, $3, $6));
}
| ArrayExpr ASSIGN LC RightValList RC
{
    $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->arr->u.id, $1->idx->u.num, nullptr, $4));
}
| ArrayExpr COLON Type ASSIGN LC RC
{
    $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->arr->u.id, $1->idx->u.num, $3, nullptr));
}
| ArrayExpr ASSIGN LC RC
{
    $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->arr->u.id, $1->idx->u.num, nullptr, nullptr));
}
;

Type: INT
{
  $$ = A_NativeType($1, A_intTypeKind);
}
| ID
{
  $$ = A_StructType($1->pos, $1->id);
}
;

// Define A New Structure
FieldDecl: ID COLON Type
{
  $$ = A_VarDecl_Scalar($1->pos, A_VarDeclScalar($1->pos, $1->id, $3));
}
| ArrayExpr COLON Type
{
  $$ = A_VarDecl_Array($1->pos, A_VarDeclArray($1->pos, $1->arr->u.id, $1->idx->u.num, $3));
}
;

StructDef: STRUCT ID LC FieldDeclList RC
{
  $$ = A_StructDef($1, $2->id, $4);
}
;

FieldDeclList: FieldDecl
{
  $$ = A_VarDeclList($1, nullptr);
}
| FieldDecl COMMA FieldDeclList
{
  $$ = A_VarDeclList($1, $3);
}
;

// Function Declaration
FnDeclStmt: FnDecl SEMICOLON
{
    $$ = A_FnDeclStmt($1->pos, $1);
}
;

FnDecl: FN ID LP ParamDecl RP // 没有返回值
{
    $$ = A_FnDecl($1, $2->id, $4, nullptr);
}
| FN ID LP ParamDecl RP ARROW Type // 有返回值
{
    $$ = A_FnDecl($1, $2->id, $4, $7);
}
;

ParamDecl: FieldDeclList
{
    $$ = A_ParamDecl($1);
}
| 
{
    $$ = A_ParamDecl(nullptr);
}
;

// Function Definition
FnDef: FnDecl CodeBlock
{
    $$ = A_FnDef($1->pos, $1, $2);
}
;

CodeBlock: LC RC{
    $$ = nullptr;
}
| LC CodeBlockStmtList RC
{
    $$ = $2;
}
;

CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList
{
    $$ = A_CodeBlockStmtList($1, $2);
}
| CodeBlockStmt
{
    $$ = A_CodeBlockStmtList($1, nullptr);
}
;

CodeBlockStmt: SEMICOLON
{
    $$ = A_BlockNullStmt($1);
}
| VarDeclStmt
{
    $$ = A_BlockVarDeclStmt($1->pos, $1);
}
| AssignStmt
{
    $$ = A_BlockAssignStmt($1->pos, $1);
}
| CallStmt
{
    $$ = A_BlockCallStmt($1->pos, $1);
}
| IfStmt
{
    $$ = A_BlockIfStmt($1->pos, $1);
}
| WhileStmt
{
    $$ = A_BlockWhileStmt($1->pos, $1);
}
| ReturnStmt
{
    $$ = A_BlockReturnStmt($1->pos, $1);
}
| ContinueStmt
{
    $$ = A_BlockContinueStmt($1);
}
| BreakStmt
{
    $$ = A_BlockBreakStmt($1);
}
;

ReturnStmt: RETURN RightVal SEMICOLON
{
    $$ = A_ReturnStmt($1, $2);
}
| RETURN SEMICOLON
{
    $$ = A_ReturnStmt($1, nullptr);
}
;

ContinueStmt: CONTINUE SEMICOLON
{
    $$ = $1;
}
;

BreakStmt: BREAK SEMICOLON
{
    $$ = $1;
}
;

CallStmt: FnCall SEMICOLON
{
    $$ = A_CallStmt($1->pos, $1);
}
;

// Control Flow
IfStmt: IF BoolUnit CodeBlock ELSE CodeBlock
{
    $$ = A_IfStmt($1, $2, $3, $5);
}
| IF BoolUnit CodeBlock
{
    $$ = A_IfStmt($1, $2, $3, nullptr);
}
;

// BoolUnit_: LP ComExpr RP
// {
//     $$ = A_ComExprUnit($2->pos, $2);
// }
// | LP BoolExpr RP
// {
//     $$ = A_BoolExprUnit($1, $2);
// }
// | LP BoolUOpExpr RP
// {
//     $$ = A_BoolUOpExprUnit($1, $2);
// }
// ;

WhileStmt: WHILE BoolUnit CodeBlock
{
    $$ = A_WhileStmt($1, $2, $3);
}
;

%%
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


