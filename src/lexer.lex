%{
#include <stdio.h>
#include <string.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
int c;
int calc(const char *s, int len);
%}

%s COMMENT_INLINE COMMENT_MULTI 

%%

<COMMENT_INLINE>[^\n]* {}
<COMMENT_INLINE>\n {
    BEGIN(INITIAL);
    ++line;
    col = 1;
}

<COMMENT_MULTI>[^*]* {}
<COMMENT_MULTI>"*/" {
    BEGIN(INITIAL);
}


<INITIAL>"//" {
    BEGIN(COMMENT_INLINE);
    col+=2;
}

<INITIAL>"/*" {
    BEGIN(COMMENT_MULTI);
    col+=2;
}

<INITIAL>"\n" { ++line; col = 1; }
<INITIAL>"\t" { col+=4; }
<INITIAL>" " { ++col; }
<INITIAL>"+" { yylval.pos = A_Pos(line,col); ++col; return ADD; }
<INITIAL>"-" { yylval.pos = A_Pos(line,col); ++col; return SUB; }
<INITIAL>"*" { yylval.pos = A_Pos(line,col); ++col; return MUL; }
<INITIAL>"/" { yylval.pos = A_Pos(line,col); ++col; return DIV; }

<INITIAL>"(" { yylval.pos = A_Pos(line,col); ++col; return LP; }
<INITIAL>")" { yylval.pos = A_Pos(line,col); ++col; return RP; }
<INITIAL>"[" { yylval.pos = A_Pos(line,col); ++col; return LB; }
<INITIAL>"]" { yylval.pos = A_Pos(line,col); ++col; return RB; }
<INITIAL>"{" { yylval.pos = A_Pos(line,col); ++col; return LC; }
<INITIAL>"}" { yylval.pos = A_Pos(line,col); ++col; return RC; }

<INITIAL>"," { yylval.pos = A_Pos(line,col); ++col; return COMMA; }
<INITIAL>";" { yylval.pos = A_Pos(line,col); ++col; return SEMICOLON; }


<INITIAL>"==" { yylval.pos = A_Pos(line,col); col+=2; return EQ; }
<INITIAL>"!=" { yylval.pos = A_Pos(line,col); col+=2; return NEQ; }
<INITIAL>">" { yylval.pos = A_Pos(line,col); col+=1; return GT; }
<INITIAL>">=" { yylval.pos = A_Pos(line,col); col+=2; return GTEQ; }
<INITIAL>"<" { yylval.pos = A_Pos(line,col); col+=1; return LT; }
<INITIAL>"<=" { yylval.pos = A_Pos(line,col); col+=2; return LTEQ; }

<INITIAL>"=" { yylval.pos = A_Pos(line,col); col+=1; return ASSIGN; }

<INITIAL>"!" { yylval.pos = A_Pos(line,col); col+=1; return NOT; }
<INITIAL>"&&" { yylval.pos = A_Pos(line,col); col+=2; return AND; }
<INITIAL>"||" { yylval.pos = A_Pos(line,col); col+=2; return OR; }

<INITIAL>":" { yylval.pos = A_Pos(line,col); ++col; return COLON; }
<INITIAL>"->" { yylval.pos = A_Pos(line,col); col+=2; return ARROW; }
<INITIAL>"." { yylval.pos = A_Pos(line,col); ++col; return DOT; }

<INITIAL>"if" { yylval.pos = A_Pos(line,col); col+=2; return IF; }
<INITIAL>"else" { yylval.pos = A_Pos(line,col); col+=4; return ELSE; }
<INITIAL>"while" { yylval.pos = A_Pos(line,col); col+=5; return WHILE; }
<INITIAL>"ret" { yylval.pos = A_Pos(line,col); col+=3; return RETURN; } 
<INITIAL>"break" { yylval.pos = A_Pos(line,col); col+=5; return BREAK; }
<INITIAL>"continue" { yylval.pos = A_Pos(line,col); col+=8; return CONTINUE; }

<INITIAL>"int" { yylval.pos = A_Pos(line,col); col+=3; return INT; }
<INITIAL>"fn" { yylval.pos = A_Pos(line,col); col+=1; return FN; } 
<INITIAL>"let" { yylval.pos = A_Pos(line,col); col+=3; return LET; }
<INITIAL>"struct" { yylval.pos = A_Pos(line,col); col+=6; return STRUCT; }

<INITIAL>[1-9][0-9]* {
    yylval.tokenNum = A_TokenNum(A_Pos(line, col), calc(yytext, yyleng)); 
    col+=yyleng;
    return NUM;
}
<INITIAL>0 {
    yylval.tokenNum = A_TokenNum(A_Pos(line, col), 0);
    col+=1;
    return NUM;
}
<INITIAL>[a-z_A-Z][a-z_A-Z0-9]* { 
    yylval.tokenId = A_TokenId(A_Pos(line, col), strdup(yytext));  // 将标识符转换为TokenId
    col+=yyleng;  // 更新列号
    return ID;
}

<INITIAL>. {
    printf("Illegal input \"%c\"\n", yytext[0]);
}
%%
// 辅助函数

// This function takes a string of digits and its length as input, and returns the integer value of the string.
int calc(const char *s, int len) {
    int ret = 0;
    for(int i = 0; i < len; i++)
        ret = ret * 10 + (s[i] - '0');  // 将字符串转换为整数
    return ret;
}