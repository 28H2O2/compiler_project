//* main 函数所在的文件，能够体现实验的总体流程
//* 读取输入文件，解析其内容生成抽象语法树，并将结果输出到另一个文件中。
#include <fstream>
#include "TeaplAst.h"
#include "TeaplaAst.h"
#include "PrintTeaplaAst.h"
#include "y.tab.hpp"

// set YACCDEBUG 1 to turn on yydebug
#define YACCDEBUG 1

using namespace std;

extern int yyparse();
extern YYSTYPE yylval;
extern int yydebug;

int line, col;

A_program root;
aA_program aroot;

int main(int argc, char * argv[]) {

    // set YACCDEBUG 1 to turn on yydebug
    #if YACCDEBUG
        yydebug = 1;  
    #endif

    line = 1;  // line number
    col = 1;   // column number
    
    freopen(argv[1], "r", stdin);  // read from input file
    ofstream ASTStream;
    ASTStream.open(argv[2]);  // 将抽象语法树输出到另一个文件中

    yyparse();  // 生成抽象语法树
    aroot = aA_Program(root);  // 将抽象语法树转换为使用STL的定义
    print_aA_Program(aroot, ASTStream);  // 将抽象语法树打印到输出文件中

    ASTStream.close();  // close the output file
    return 0;  // return 0 to indicate success
}