#include "TypeCheck.h"

// global tabels
typeMap func2retType; // 储存函数的返回值类型

// global token ids to type
typeMap g_token2Type;

// local token ids to type, since func param can override global param
typeMap funcparam_token2Type;
vector<typeMap *> local_token2Type;

paramMemberMap func2Param;     // 储存全体函数的参数列表
paramMemberMap struct2Members; // 储存全体结构体的成员列表

fnStateMap fnState;

string current_func;


// private util functions
void error_print(std::ostream &out, A_pos p, string info)
{
    out << "Typecheck error in line " << p->line << ", col " << p->col << ": " << info << std::endl;
    exit(0);
}

void print_token_map(typeMap *map)
{
    for (auto it = map->begin(); it != map->end(); it++)
    {
        std::cout << it->first << " : ";
        switch (it->second->type->type)
        {
        case A_dataType::A_nativeTypeKind:
            switch (it->second->type->u.nativeType)
            {
            case A_nativeType::A_intTypeKind:
                std::cout << "int";
                break;
            default:
                break;
            }
            break;
        case A_dataType::A_structTypeKind:
            std::cout << *(it->second->type->u.structType);
            break;
        default:
            break;
        }
        switch (it->second->isVarArrFunc)
        {
        case 0:
            std::cout << " scalar";
            break;
        case 1:
            std::cout << " array";
            break;
        case 2:
            std::cout << " function";
            break;
        }
        std::cout << std::endl;
    }
    std::cout << "print_token_map end" << std::endl;
}

void print_token_maps()
{
    std::cout << "global token2Type:" << std::endl;
    print_token_map(&g_token2Type);
    std::cout << "local token2Type:" << std::endl;
    print_token_map(&funcparam_token2Type);
}

bool comp_aA_type(aA_type target, aA_type t)
{
    if (!target || !t)
        return false;
    if (target->type != t->type)
        return false;
    if (target->type == A_dataType::A_nativeTypeKind)
        if (target->u.nativeType != t->u.nativeType)
            return false;
    if (target->type == A_dataType::A_structTypeKind)
        if (target->u.structType != t->u.structType)
            return false;
    return true;
}

bool comp_tc_type(tc_type target, tc_type t)
{
    if (!target || !t)
        return false;

    // arr kind first
    if (target->isVarArrFunc && t->isVarArrFunc == 0)
        return false;

    // if target type is nullptr, alwayse ok
    return comp_aA_type(target->type, t->type);
}

bool comp_params(vector<aA_varDecl> *target, vector<aA_varDecl> *params)
{
    if (target->size() != params->size())
        return false;

    for (int i = 0; i < target->size(); i++)
    {
        aA_varDecl a = params->at(i);
        aA_varDecl b = target->at(i);

        if (a->kind == A_varDeclScalarKind && b->kind == A_varDeclScalarKind)
        {
            if (!comp_aA_type(a->u.declScalar->type, b->u.declScalar->type))
                return false;
        }
        else if (a->kind == A_varDeclArrayKind && b->kind == A_varDeclArrayKind)
        {
            if (!comp_aA_type(a->u.declArray->type, b->u.declArray->type))
                return false;
        }
        else
            return false;
    }
    return true;
}

tc_type tc_Type(aA_type t, uint isVarArrFunc)
{
    tc_type ret = new tc_type_;
    ret->type = t;
    ret->isVarArrFunc = isVarArrFunc;
    return ret;
}

tc_type tc_Type(aA_varDecl vd)
{
    if (vd->kind == A_varDeclType::A_varDeclScalarKind)
        return tc_Type(vd->u.declScalar->type, 0);
    else if (vd->kind == A_varDeclType::A_varDeclArrayKind)
        return tc_Type(vd->u.declArray->type, 1);
    return nullptr;
}

tc_type tc_Type(aA_varDef vd)
{
    if (vd->kind == A_varDefType::A_varDefScalarKind)
        return tc_Type(vd->u.defScalar->type, 0);
    else if (vd->kind == A_varDefType::A_varDefArrayKind)
        return tc_Type(vd->u.defArray->type, 1);
    return nullptr;
}

// public functions
// check_Prog(std::cout, aroot);
void check_Prog(std::ostream &out, aA_program p)
{
    std::cout << std::endl;
    // 检查全局变量，struct

    for (auto ele : p->programElements)
    {
        if (ele->kind == A_programVarDeclStmtKind)
        {
            // std::cout << "vardecl" << std::endl;
            // varDeclStmt := < let > (varDecl | varDef) < ; >
            //  varDecl := id < : > type |  id < [ > num < ] >< : > type | id |  id < [ > num < ] >
            check_GlobalVarDecl(out, ele->u.varDeclStmt); // 全局变量
        }
        else if (ele->kind == A_programStructDefKind)
        {
            // std::cout << "structDef" << std::endl;
            // structDef := < struct > id < { > (varDecl) (< , > varDecl)* < } >
            check_StructDef(out, ele->u.structDef); // 全局结构体
        }
    }

    // 检查函数
    for (auto ele : p->programElements)
    {
        if (ele->kind == A_programFnDeclStmtKind)
        {
            // std::cout << "fnDeclStmt" << std::endl;
            // fnDeclStmt := fnDecl < ; >

            // fnDecl := < fn > id < ( > paramDecl < ) > //without return value
            //        | < fn > id < ( > paramDecl < ) > < -> > type //with return value

            check_FnDeclStmt(out, ele->u.fnDeclStmt);
        }
        else if (ele->kind == A_programFnDefKind)
        {
            // std::cout << "fnDeclDef" << std::endl;
            //
            check_FnDefStmt(out, ele->u.fnDef);
        }
    }

    // 检查函数定义
    for (auto ele : p->programElements)
    {
        if (ele->kind == A_programFnDefKind)
        {
            // std::cout << "fnDef" << std::endl;
            // fnDef := fnDecl codeBlock
            check_FnDef(out, ele->u.fnDef);
        }
        else if (ele->kind == A_programNullStmtKind)
        {
            // do nothing
        }
    }

    out << "Typecheck passed!" << std::endl;
    return;
}
void check_Global(std::ostream &out, string name, A_pos pos)
{
    // 检查全局变量

    if (!pos)
        return;

    // 不能与已有全局变量重名
    if (g_token2Type.find(name) != g_token2Type.end())
    {
        error_print(out, pos, "This id is already defined!");
    }

    // 不能与struct重名
    if (struct2Members.find(name) != struct2Members.end())
    {
        error_print(out, pos, "This id is already defined!");
    }

    // 不能与函数名重名
    if (func2Param.find(name) != func2Param.end())
    {
        error_print(out, pos, "This id is already defined!");
    }
}


void check_GlobalVarDecl(std::ostream &out, aA_varDeclStmt vd)
{
    // 检查全局变量
    if (!vd)
        return;
    string name;
    if (vd->kind == A_varDeclStmtType::A_varDeclKind)
    {
        // 无赋值
        //  分为scalar 和 array
        if (vd->u.varDecl->kind == A_varDeclType::A_varDeclScalarKind)
        {
            name = *vd->u.varDecl->u.declScalar->id;
            check_Global(out, name, vd->pos);
            g_token2Type[name] = tc_Type(vd->u.varDecl);
            if (vd->u.varDecl->u.declScalar->type != nullptr)
            {
                // 如果有类型，检查是否存在
                if (vd->u.varDecl->u.declScalar->type->type == A_dataType::A_structTypeKind)
                {
                    if (struct2Members.find(*(vd->u.varDecl->u.declScalar->type->u.structType)) == struct2Members.end())
                        error_print(out, vd->pos, "Struct does not exist!");
                }
            }
        }
        else if (vd->u.varDecl->kind == A_varDeclType::A_varDeclArrayKind)
        {
            name = *vd->u.varDecl->u.declArray->id;
            check_Global(out, name, vd->pos);
            g_token2Type[name] = tc_Type(vd->u.varDecl);

            if (vd->u.varDecl->u.declArray->type != nullptr)
            {
                if (vd->u.varDecl->u.declArray->type->type == A_dataType::A_structTypeKind)
                {
                    if (struct2Members.find(*(vd->u.varDecl->u.declArray->type->u.structType)) == struct2Members.end())
                        error_print(out, vd->pos, "Struct does not exist!");
                }
            }
        }
        else
            error_print(out, vd->pos, "Unknown varDeclType!");

        // std::cout << "---------------------------varDecl name: " << name << std::endl;
    }
    else if (vd->kind == A_varDeclStmtType::A_varDefKind)
    {
        // 有赋值
        // 分为scalar 和 array
        if (vd->u.varDef->kind == A_varDefType::A_varDefScalarKind)
            name = *vd->u.varDef->u.defScalar->id;
        else if (vd->u.varDef->kind == A_varDefType::A_varDefArrayKind)
            name = *vd->u.varDef->u.defArray->id;
        else
            error_print(out, vd->pos, "Unknown varDefType!");

        check_Global(out, name, vd->pos);

        aA_varDef vdef = vd->u.varDef;
        // 标量
        if (vd->u.varDef->kind == A_varDefType::A_varDefScalarKind)
        {
            tc_type t = new tc_type_;
            t = check_ArithExpr(out, vd->u.varDef->u.defScalar->val->u.arithExpr);

            if (vdef->u.defScalar->type != nullptr)
            {
                if (!comp_aA_type(vdef->u.defScalar->type, t->type))
                    error_print(out, vd->pos, "Type does not match!");
            }
            else
            {
                // 如果没有类型，赋值类型就是类型
                vdef->u.defScalar->type = t->type;
            }
            g_token2Type[name] = tc_Type(vd->u.varDef);
        }
        // 数组
        else if (vd->u.varDef->kind == A_varDefType::A_varDefArrayKind)
        {
            int array_len = vdef->u.defArray->len;
            if (array_len != vdef->u.defArray->vals.size())
                error_print(out, vd->pos, "Array length does not match!");

            tc_type t = new tc_type_;
            t = check_ArithExpr(out, vdef->u.defArray->vals[0]->u.arithExpr);

            if (vdef->u.defArray->type != nullptr)
            {
                if (!comp_aA_type(vdef->u.defArray->type, t->type))
                    error_print(out, vd->pos, "Type does not match!");
            }
            else
            {
                // 如果没有类型，赋值类型就是类型
                vdef->u.defArray->type = t->type;
            }

            for(aA_rightVal rv : vdef->u.defArray->vals)
            {
                tc_type ret = new tc_type_;
                ret = check_ArithExpr(out, rv->u.arithExpr);
                if (!comp_aA_type(t->type, ret->type))
                    error_print(out, vd->pos, "Type does not match!");
            }
            g_token2Type[name] = tc_Type(vd->u.varDef);
        }
    }
    else
    {
        error_print(out, vd->pos, "Unknown varDeclStmtType!");
    }
}
void check_name(string name, std::ostream &out, aA_varDeclStmt vd)
{
    if (g_token2Type.find(name) != g_token2Type.end())
        error_print(out, vd->pos, "Global variable name conflict");

    if (func2Param.find(name) != func2Param.end())
        error_print(out, vd->pos, "Function name conflict");

    if (funcparam_token2Type.find(name) != funcparam_token2Type.end())
        error_print(out, vd->pos, "Function parameter name conflict");

    if (struct2Members.find(name) != struct2Members.end())
        error_print(out, vd->pos, "Struct name conflict");

    if (local_token2Type.size() > 0 && local_token2Type.back()->find(name) != local_token2Type.back()->end())
        error_print(out, vd->pos, "Local variable name conflict");
}

void check_VarDecl(std::ostream &out, aA_varDeclStmt vd)
{
    if (!vd)
        return;
    string name;

    if (vd->kind == A_varDeclStmtType::A_varDeclKind)
    {
        // decl only
        // if declaration only
        // Example:
        //   let a:int;
        //   let a[5]:int; 无赋值的情况

        aA_varDecl vdecl = vd->u.varDecl;
        tc_type t = new tc_type_;
        if (vdecl->kind == A_varDeclType::A_varDeclScalarKind)
        {
            name = *vdecl->u.declScalar->id;
            check_name(name, out, vd);
            if (vdecl->u.declScalar->type != nullptr)
            {
                if (vdecl->u.declScalar->type->type == A_dataType::A_structTypeKind)
                {
                    if (struct2Members.find(*(vdecl->u.declScalar->type->u.structType)) == struct2Members.end())
                        error_print(out, vd->pos, "Struct does not exist!");
                }
            }

            t = tc_Type(vdecl->u.declScalar->type, 0);
        }
        else if (vdecl->kind == A_varDeclType::A_varDeclArrayKind)
        {
            name = *vdecl->u.declArray->id;
            check_name(name, out, vd);

            if (vdecl->u.declArray->type != nullptr)
            {
                if (vdecl->u.declArray->type->type == A_dataType::A_structTypeKind)
                {
                    if (struct2Members.find(*(vdecl->u.declArray->type->u.structType)) == struct2Members.end())
                        error_print(out, vd->pos, "Struct does not exist!");
                }
            }

            t = tc_Type(vdecl->u.declArray->type, 1);
        }

        // tc_type t = tc_Type(vdecl->u.declScalar->type, 0);

        // if(vdecl->u.declScalar->type == nullptr)
        //     std::cout << name << "------------null" << std::endl;

        local_token2Type.back()->insert(std::make_pair(name, t));
    }
    else if (vd->kind == A_varDeclStmtType::A_varDefKind)
    {
        // decl and def
        // 有赋值的情况
        aA_varDef vdef = vd->u.varDef;
        if (vdef->kind == A_varDefType::A_varDefScalarKind)
        {
            name = *vdef->u.defScalar->id;
        }
        else if (vdef->kind == A_varDefType::A_varDefArrayKind)
        {
            name = *vdef->u.defArray->id;
            /* fill code here, allow omited type */
        }

        /* fill code here, allow omited type */
        // 不能和全局变量重名
        // 不能和已有局部变量重名
        // 不能和函数名重名
        // 不能和函数形参重名
        // 不能和struct重名
        check_name(name, out, vd);

        // TODO: 右值可以为各种表达式..., 所以应该check表达式然后返回类型
        if (vdef->kind == A_varDefType::A_varDefScalarKind)
        {
            tc_type t = new tc_type_;
            t = check_ArithExpr(out, vdef->u.defScalar->val->u.arithExpr);

            if (vdef->u.defScalar->type != nullptr)
            {
                if (!comp_aA_type(vdef->u.defScalar->type, t->type))
                    error_print(out, vd->pos, "Type does not match!");
            }
            else
            {
                // 如果没有类型，赋值类型就是类型
                vdef->u.defScalar->type = t->type;
            }
            local_token2Type.back()->insert(std::make_pair(name, t));
        }
        else if (vdef->kind == A_varDefType::A_varDefArrayKind)
        {
            // 检查长度
            int array_len = vdef->u.defArray->len;
            if (array_len != vdef->u.defArray->vals.size())
                error_print(out, vd->pos, "Array length does not match!");

            // 获取第一个右值的类型
            tc_type t = new tc_type_;
            t = check_ArithExpr(out, vdef->u.defArray->vals[0]->u.arithExpr);

            if (vdef->u.defArray->type != nullptr)
            {
                if (!comp_aA_type(vdef->u.defArray->type, t->type))
                    error_print(out, vd->pos, "Type does not match!");
            }
            else
            {
                // 如果没有类型，赋值类型就是类型
                vdef->u.defArray->type = t->type;
            }

            for (aA_rightVal rv : vdef->u.defArray->vals)
            {
                // 检查每个右值
                tc_type ret = new tc_type_;
                ret = check_ArithExpr(out, rv->u.arithExpr);
                if (!comp_aA_type(t->type, ret->type))
                    error_print(out, vd->pos, "Type does not match!");
            }
            tc_type local = tc_Type(vdef->u.defArray->type, 1);

            local_token2Type.back()->insert(std::make_pair(name, local));
        }
        else
        {
            error_print(out, vd->pos, "Unknown varDefType!");
        }
    }
    return;
}

void check_StructDef(std::ostream &out, aA_structDef sd)
{
    if (!sd)
        return;
    string name = *sd->id;
    if (struct2Members.find(name) != struct2Members.end())
        error_print(out, sd->pos, "This id is already defined!");
    struct2Members[name] = &(sd->varDecls);
    // std::cout << "struct name aasdasdasdasda-----"<< name << std::endl;
    return;
}

void check_FnDecl(std::ostream &out, aA_fnDecl fd)
{
    if (!fd)
        return;
    string name = *fd->id;

    // std::cout << "" << std::endl;
    // 函数声明不能与struct 全局变量重名
    if (struct2Members.find(name) != struct2Members.end())
        error_print(out, fd->pos, "This id is already defined!");

    if (g_token2Type.find(name) != g_token2Type.end())
        error_print(out, fd->pos, "This id is already defined!");

    // if already declared, should match
    // 不支持函数重载
    // 查找是否已经声明
    if (func2Param.find(name) != func2Param.end())
    {
        // 已经申明，检查是否匹配

        // 检查函数返回值类型是否匹配
        auto it = func2retType.find(name);
        // std::cout << it->first << std::endl;
        if (!comp_aA_type(fd->type, it->second->type))
            error_print(out, fd->pos, "Return type does not match!");

        // 检查函数参数列表是否匹配
        if (!comp_params(func2Param[name], &(fd->paramDecl->varDecls)))
            error_print(out, fd->pos, "Function parameters do not match!");
    }
    else
    {
        // 如果没有定义过
        // 加入到func2Param func2retType
        func2Param[name] = &(fd->paramDecl->varDecls);
        func2retType[name] = tc_Type(fd->type, 2);
    }
    return;
}

void check_FnDeclStmt(std::ostream &out, aA_fnDeclStmt fd)
{
    //  fn main(a:int, b:int)->int;
    if (!fd)
        return;

    string name = *fd->fnDecl->id;
    // std::cout << "fnDeclStmt name: " << name << std::endl;
    // 检查函数是否已经定义或声明
    if (fnState.find(name) != fnState.end())
    {
        if (fnState[name] == A_programElementType::A_programFnDefKind)
            error_print(out, fd->pos, "Function has been defined!");
        else if (fnState[name] == A_programElementType::A_programFnDeclStmtKind)
            error_print(out, fd->pos, "Function has been declared!");
        else
            error_print(out, fd->pos, "Unknown function state!");
    }
    check_FnDecl(out, fd->fnDecl);

    fnState[name] = A_programElementType::A_programFnDeclStmtKind;
    return;
}

void check_FnDefStmt(std::ostream &out, aA_fnDef fd)
{
    if (!fd)
        return;

    string func_name = *(fd->fnDecl->id);

    // 检查是否已经定义
    if (fnState.find(func_name) != fnState.end() && fnState[func_name] == A_programElementType::A_programFnDefKind)
        error_print(out, fd->pos, "Function has been defined!");

    // should match if declared
    // 检查是否已经声明，如果已经声明，检查是否匹配
    // 没有声明过，加入到func2Param func2retType
    check_FnDecl(out, fd->fnDecl);

    // 更改状态为已定义
    fnState[func_name] = A_programElementType::A_programFnDefKind;
}

void check_FnDef(std::ostream &out, aA_fnDef fd)
{

    vector<string> params;
    funcparam_token2Type.clear();
    // std::cout << "test funcparam_token-------" << std::endl;
    // print_token_map(&funcparam_token2Type);
    // add params to local tokenmap, func params override global ones
    for (aA_varDecl vd : fd->fnDecl->paramDecl->varDecls)
    {
        // aA_varDecl  A_varDeclScalarKind   A_varDeclArrayKind
        // 函数参数 不考虑带有默认参数的情况 main(a:int=10)
        // 则参数都是变量声明 都是局部变量

        if (vd->kind == A_varDeclScalarKind)
        {
            // 检查同一函数的参数是否重名
            // vd->u.declScalar->id  在params中
            if (std::find(params.begin(), params.end(), *(vd->u.declScalar->id)) != params.end())
            {
                error_print(out, vd->pos, "Function parameters should not duplicate!");
            }
            else
            {
                string name = *(vd->u.declScalar->id);
                params.emplace_back(name);
                funcparam_token2Type[name] = tc_Type(vd->u.declScalar->type, 0);
            }
        }
        else if (vd->kind == A_varDeclArrayKind)
        {
            if (std::find(params.begin(), params.end(), *(vd->u.declArray->id)) != params.end())
            {
                error_print(out, vd->pos, "Function parameters should not duplicate!");
            }
            else
            {
                string name = *(vd->u.declArray->id);
                params.push_back(name);
                funcparam_token2Type[name] = tc_Type(vd->u.declArray->type, 1);
            }
        }
    }

    // 加入到local_token2Type funcparam_token2Type
    // print_token_map(&funcparam_token2Type);
    // std::cout << "test funcparam_token-------" << std::endl;
    // print_token_map(&funcparam_token2Type);
    local_token2Type.push_back(new typeMap(funcparam_token2Type));

    // std::cout << "params: "<< params.size() << std::endl;
    // std::cout << "local size: "<< local_token2Type.size() << std::endl;

    current_func = *(fd->fnDecl->id);
    // 检查代码部分
    for (aA_codeBlockStmt stmt : fd->stmts)
    {
        check_CodeblockStmt(out, stmt); 

        // return value type should match
        /* fill code here */
    }
    // std::cout << "check" << std::endl;

    // 函数结束，弹出local_token2Type栈顶元素
    local_token2Type.pop_back();

    // std::cout << "check pop" << std::endl;

    return;
}

void check_CodeblockStmt(std::ostream &out, aA_codeBlockStmt cs)
{
    if (!cs)
        return;

    // variables declared in a code block should not duplicate with outer ones.
    switch (cs->kind)
    {
    // 检查变量声明
    case A_codeBlockStmtType::A_varDeclStmtKind:
        check_VarDecl(out, cs->u.varDeclStmt);
        break;

    // 检查赋值语句
    case A_codeBlockStmtType::A_assignStmtKind:
        check_AssignStmt(out, cs->u.assignStmt);
        break;

    // 检查if
    case A_codeBlockStmtType::A_ifStmtKind:
        check_IfStmt(out, cs->u.ifStmt);
        break;

    // 检查while
    case A_codeBlockStmtType::A_whileStmtKind:
        check_WhileStmt(out, cs->u.whileStmt);
        break;

    // 检查函数调用
    case A_codeBlockStmtType::A_callStmtKind:
        check_CallStmt(out, cs->u.callStmt);
        break;

    // 检查return
    case A_codeBlockStmtType::A_returnStmtKind:
        check_ReturnStmt(out, cs->u.returnStmt);
        break;
    default:
        break;
    }

    return;
}
tc_type check_leftValExists(std::ostream &out, A_pos pos, string name)
{

    if (local_token2Type.back()->find(name) != local_token2Type.back()->end())
        return local_token2Type.back()->at(name);

    if (g_token2Type.find(name) != g_token2Type.end())
        return g_token2Type[name];

    error_print(out, pos, "Variable does not exist!");
    return nullptr;
}

void check_AssignStmt(std::ostream &out, aA_assignStmt as)
{
    if (!as)
        return;
    string name;
    tc_type left_type; // deduced type if type is omitted at decl
    switch (as->leftVal->kind)
    {
    case A_leftValType::A_varValKind:
    {
        name = *as->leftVal->u.id;
        /* fill code here */
        // 不能给函数赋值
        if (func2Param.find(name) != func2Param.end())
            error_print(out, as->pos, "Function cannot be assigned!");

        // 不能给函数参数赋值
        if (funcparam_token2Type.find(name) != funcparam_token2Type.end())
            error_print(out, as->pos, "Function parameter cannot be assigned!");

        // left_type = check_scalarExists(out, as->pos, name);

        left_type = check_leftValExists(out, as->pos, name);

        // std::cout <<" check left" << std::endl;
        // std::cout << "name: " << name << std::endl;
    }
    break;
    case A_leftValType::A_arrValKind:
    {
        name = *as->leftVal->u.arrExpr->arr->u.id;
        /* fill code here */
        // b[0] 应该记为0
        left_type = check_ArrayExpr(out, as->leftVal->u.arrExpr);
    }
    break;
    case A_leftValType::A_memberValKind:
    {
        /* fill code here */
        // std::cout << "-----member----"<<std::endl;
        left_type = check_MemberExpr(out, as->leftVal->u.memberExpr);
    }
    break;
    }

    // check 右值
    // 查询右值是否是array的变量名

    tc_type right_type = check_ArithExpr(out, as->rightVal->u.arithExpr);

    if (left_type->type != nullptr) 
    {
        if (!comp_tc_type(left_type, right_type))
            error_print(out, as->pos, "Type does not match!");
    }
    else
    {
        // 如果没有类型，赋值类型就是类型
        // 对原本的空修改类型
        // 在local中找到name，修改类型
        if (local_token2Type.back()->find(name) != local_token2Type.back()->end())
        {
            local_token2Type.back()->at(name)->type = right_type->type;
        }
        else
        {
            // 在全局中找到name，修改类型
            if (g_token2Type.find(name) != g_token2Type.end())
            {
                g_token2Type[name]->type = right_type->type;
            }
        }
    }

    return;
}

tc_type check_ArrayExpr(std::ostream &out, aA_arrayExpr ae)
{
    /*
      Example:
          a[1] = 0;
      Hint:
          check the validity of the array index   
    */

    tc_type ret = new tc_type_;
    if (!ae)
        return nullptr;
    string name = *ae->arr->u.id;

    // 检查array存在
    // std::cout << "check array expr ---" << name << std::endl;
    ret = check_arrayExists(out, ae->pos, name);

    // a[0] 记为scalar
    ret->isVarArrFunc = 0;

    // 检查一下index 如果是变量，得存在且为int
    if (ae->idx->kind == A_indexExprKind::A_idIndexKind)
    {
        // std::cout << "check array index" << std::endl;
        tc_type r = new tc_type_;
        r = check_scalarExists(out, ae->idx->pos, *ae->idx->u.id);

        // 必须是int类型;
        if (r->type->type != A_dataType::A_nativeTypeKind)
            error_print(out, ae->idx->pos, "Index must be int type!");
    }
    else if (ae->idx->kind == A_indexExprKind::A_numIndexKind)
    {
        // 必须是int类型且不为负
        if (ae->idx->u.num < 0)
            error_print(out, ae->idx->pos, "Index must be positive!");
    }
    else
    {
        error_print(out, ae->pos, "Unknown index kind!");
    }

    /* fill code here */
    return ret;
}

tc_type check_MemberExpr(std::ostream &out, aA_memberExpr me)
{
    /*
      Example:
          a.b
    */

    // check if the member exists and return the tyep of the member
    if (!me)
        return nullptr;

    string name = *me->structId->u.id;

    // check struct name
    /* fill code here */
    A_pos pos = me->pos;
    tc_type ret = new tc_type_;
    ret = check_scalarExists(out, pos, name);

    if (ret->type->type != A_dataType::A_structTypeKind)
        error_print(out, pos, "Variable is not a struct!");

    // check member name
    /* fill code here */
    if (struct2Members.find(*(ret->type->u.structType)) == struct2Members.end())
        error_print(out, pos, "Struct does not exist!");

    auto it = struct2Members[*(ret->type->u.structType)];

    // check 成员是否存在
    for (aA_varDecl vd : *it)
    {
        if (vd->kind == A_varDeclScalarKind)
        {
            if (*(vd->u.declScalar->id) == *me->memberId)
            {
                // 成员存在
                return tc_Type(vd);
            }
        }
    }

    error_print(out, pos, "Member does not exist!");
    return nullptr;
}

void before_block()
{
    // 以当前local的最后一次为模版复制一份
    typeMap *new_local = new typeMap(*local_token2Type.back());
    local_token2Type.push_back(new_local);
}

void after_block()
{
    // 弹出当前local
    local_token2Type.pop_back();
}

void check_IfStmt(std::ostream &out, aA_ifStmt is)
{
    if (!is)
        return;
    // check_BoolExpr(out, is->boolExpr);
    check_BoolUnit(out, is->boolUnit);
    /* fill code here, take care of variable scope */

    // std::cout << "-----if-else------" <<std::endl;

    before_block();
    // 判断if语句块
    for (aA_codeBlockStmt s : is->ifStmts)
    {
        check_CodeblockStmt(out, s);
    }
    after_block();

    before_block();
    // 判断else语句块
    for (aA_codeBlockStmt s : is->elseStmts)
    {
        check_CodeblockStmt(out, s);
    }
    after_block();

    /* fill code here */
    return;
}

void check_BoolExpr(std::ostream &out, aA_boolExpr be)
{
    if (!be)
        return;
    switch (be->kind)
    {
    case A_boolExprType::A_boolBiOpExprKind:
        check_BoolExpr(out, be->u.boolBiOpExpr->left);
        check_BoolExpr(out, be->u.boolBiOpExpr->right);
        break;
    case A_boolExprType::A_boolUnitKind:
        check_BoolUnit(out, be->u.boolUnit);
        break;
    default:
        break;
    }
    return;
}

void check_BoolUnit(std::ostream &out, aA_boolUnit bu)
{
    if (!bu)
        return;
    switch (bu->kind)
    {
    case A_boolUnitType::A_comOpExprKind:
    {
        /* fill code here */
        // 检查左值 右值 同类型
        tc_type left = check_ExprUnit(out, bu->u.comExpr->left);
        tc_type right = check_ExprUnit(out, bu->u.comExpr->right);

        if (!comp_tc_type(left, right))
            error_print(out, bu->pos, " Compare type does not match!");
    }
    break;
    case A_boolUnitType::A_boolExprKind:
        check_BoolExpr(out, bu->u.boolExpr);
        break;
    case A_boolUnitType::A_boolUOpExprKind:
        check_BoolUnit(out, bu->u.boolUOpExpr->cond);
        break;
    default:
        break;
    }
    return;
}

tc_type check_scalarExists(std::ostream &out, A_pos pos, string name)
{
    // 局部变量会覆盖全局变量
    // 先检查局部变量
    tc_type ret = new tc_type_;

    int flag = 0;

    if (local_token2Type.size() > 0)
    {

        typeMap *local = local_token2Type.back();
        if (local->find(name) != local->end())
        {
            //  找到了
            // 检查是否是scalar

            // if ((*local)[name]->isVarArrFunc == 1)
            //     error_print(out, pos, name + string(" is array."));
            // else
            ret = (*local)[name];
            flag = 1;
        }
    }

    if (flag == 1)
        return ret;

    // 再检查全局变量
    if (g_token2Type.find(name) != g_token2Type.end())
    {
        // std::cout << "check "<<std::endl;
        // print_token_map(&g_token2Type);
        // if (g_token2Type[name]->isVarArrFunc == 1)
        //     error_print(out, pos, name + string(" is array."));
        // else
        ret = g_token2Type[name];

        flag = 1; 
    }

    if (flag == 1)
        return ret;

    error_print(out, pos, "Variable does not exist!");
    return nullptr;
}

tc_type check_ExprUnit(std::ostream &out, aA_exprUnit eu)
{
    // return the aA_type of expr eu

    // exprUnit :=  num | id | < ( > arithExpr < ) > | fnCall | id < [ > id | num < ] > | id < . > id | arithUOp exprUnit

    if (!eu)
        return nullptr;
    tc_type ret;
    switch (eu->kind)
    {
    case A_exprUnitType::A_idExprKind:
    {

        ret = check_scalarExists(out, eu->pos, *eu->u.id);
    }
    break;
    case A_exprUnitType::A_numExprKind:
    {
        // std::cout << "--------num-------" << std::endl;
        aA_type numt = new aA_type_;
        numt->pos = eu->pos;
        numt->type = A_dataType::A_nativeTypeKind;
        numt->u.nativeType = A_nativeType::A_intTypeKind;
        ret = tc_Type(numt, 0);
    }
    break;
    case A_exprUnitType::A_fnCallKind:
    {
        // std::cout << "--------fncall-------" << *eu->u.id << std::endl;
        ret = check_FuncCall(out, eu->u.callExpr);
        // check_FuncCall will check if the function is defined
        /* fill code here */
    }
    break;
    case A_exprUnitType::A_arrayExprKind:
    {
        // std::cout << "--------array-------" << *eu->u.id << std::endl;
        ret = check_ArrayExpr(out, eu->u.arrayExpr);
        /* fill code here */
    }
    break;
    case A_exprUnitType::A_memberExprKind:
    {

        // std:: cout << "--------member-------"<<std::endl;
        ret = check_MemberExpr(out, eu->u.memberExpr);
    }
    break;
    case A_exprUnitType::A_arithExprKind:
    {
        // std::cout << "--------arith-------" << *eu->u.id << std::endl;
        ret = check_ArithExpr(out, eu->u.arithExpr);
    }
    break;
    case A_exprUnitType::A_arithUExprKind:
    {
        ret = check_ExprUnit(out, eu->u.arithUExpr->expr);
    }
    break;
    }
    return ret;
}

tc_type check_ArithExpr(std::ostream &out, aA_arithExpr ae)
{
    if (!ae)
        return nullptr;
    tc_type ret;
    switch (ae->kind)
    {
    case A_arithExprType::A_exprUnitKind:
    {
        // std::cout << "exprUnitKind" << ae->u.exprUnit->u.id << std::endl;
        ret = check_ExprUnit(out, ae->u.exprUnit);
    }
    break;
    case A_arithExprType::A_arithBiOpExprKind:
    {
        // std:: cout << "arithBiOpExprKind" << ae->u.arithBiOpExpr->left->u.exprUnit->u.id << std::endl;
        ret = check_ArithExpr(out, ae->u.arithBiOpExpr->left);
        tc_type rightTyep = check_ArithExpr(out, ae->u.arithBiOpExpr->right);

        if (ret->type->type > 0 || ret->type->type != A_dataType::A_nativeTypeKind || ret->type->u.nativeType != A_nativeType::A_intTypeKind ||
            rightTyep->type->type > 0 || rightTyep->type->type != A_dataType::A_nativeTypeKind || rightTyep->type->u.nativeType != A_nativeType::A_intTypeKind)
            error_print(out, ae->pos, "Only int can be arithmetic expression operation values!");
    }
    break;
    }
    return ret;
}

tc_type check_FuncCall(std::ostream &out, aA_fnCall fc)
{
    tc_type ret = new tc_type_;

    if (!fc)
        return ret;

    // Example:
    //      foo(1, 2);
    // check if function defined
    string func_name = *fc->fn;
    /* fill code here */
    if (func2Param.find(func_name) == func2Param.end())
        error_print(out, fc->pos, func_name + " Function does not exist!");

    // 如果长度不符合
    if (fc->vals.size() != func2Param[func_name]->size())
        error_print(out, fc->pos, "Function parameters do not match!");

    // check if parameter list matches
    for (int i = 0; i < fc->vals.size(); i++)
    {
        // 检查参数类型是否匹配
        aA_varDecl param = func2Param[func_name]->at(i);
        aA_rightVal val = fc->vals[i];
        if (param->kind == A_varDeclType::A_varDeclScalarKind)
        {  
            aA_varDeclScalar scalar = param->u.declScalar;

            // 检查参数类型是否匹配
            tc_type t = new tc_type_;
            t = check_ArithExpr(out, val->u.arithExpr);

            if (!comp_tc_type(tc_Type(scalar->type, 0), t))
                error_print(out, fc->pos, "Function call parameters do not match!");
        }
        else if (param->kind == A_varDeclType::A_varDeclArrayKind)
        {

            aA_varDeclArray array = param->u.declArray;

            // 检查参数类型是否匹配
            if (val->kind == A_rightValType::A_arithExprValKind &&
                val->u.arithExpr->kind == A_arithExprType::A_exprUnitKind &&
                val->u.arithExpr->u.exprUnit->kind == A_exprUnitType::A_idExprKind)
            {
                string name = *val->u.arithExpr->u.exprUnit->u.id;
                tc_type t = check_arrayExists(out, fc->pos, name);

                if (!comp_tc_type(tc_Type(array->type, 1), t))
                    error_print(out, fc->pos, "Function call parameters do not match!");
            }
            else
                error_print(out, fc->pos, "error function call");
        }
    }

    ret = func2retType[func_name];

    return ret;
}

tc_type check_arrayExists(std::ostream &out, A_pos pos, string name)
{
    tc_type ret = new tc_type_;

    // 先检查局部变量
    int flag = 0;
    if (local_token2Type.size() > 0)
    {
        // std::cout << " local ---- check array" << std::endl;
        typeMap *local = local_token2Type.back();
        if (local->find(name) != local->end())
        {
            //  找到了
            // 检查是否是array
            if ((*local)[name]->isVarArrFunc != 1)
                error_print(out, pos, name + string(" is not array."));
            else
                ret = (*local)[name];
            flag = 1;
        }
    }

    if (flag == 1)
        return ret;

    // 再检查全局变量
    if (g_token2Type.find(name) != g_token2Type.end())
    {
        if (g_token2Type[name]->isVarArrFunc != 1)
            error_print(out, pos, name + string(" is not array."));
        else
            ret = g_token2Type[name];
        flag = 1;
    }

    if (flag == 1)
        return ret;

    error_print(out, pos, "Array does not exist!");
    return nullptr;
}

void check_WhileStmt(std::ostream &out, aA_whileStmt ws)
{
    if (!ws)
        return;
    // check_BoolExpr(out, ws->boolExpr);
    check_BoolUnit(out, ws->boolUnit);
    /* fill code here, take care of variable scope */

    before_block();
    for (aA_codeBlockStmt s : ws->whileStmts)
    {
        check_CodeblockStmt(out, s);
    }
    /* fill code here */
    after_block();

    return;
}

void check_CallStmt(std::ostream &out, aA_callStmt cs)
{
    if (!cs)
        return;
    check_FuncCall(out, cs->fnCall);
    return;
}
 
void check_ReturnStmt(std::ostream &out, aA_returnStmt rs)
{
    if (!rs)
        return;

    if (rs->retVal->kind == A_rightValType::A_arithExprValKind)
    {
        // 检查返回值类型是否匹配
        // std::cout << "check return " << std::endl;
        tc_type ret = check_ArithExpr(out, rs->retVal->u.arithExpr);

        // 与当前函数返回值类型比较
        if (!comp_aA_type(func2retType[current_func]->type, ret->type))
            error_print(out, rs->pos, "Return type does not match!");

    }
    else if (rs->retVal->kind == A_rightValType::A_boolExprValKind)
    {
        // 答应我不返回bool类型
    }
    else
    {
        error_print(out, rs->pos, "Unknown return value kind!");
    }

    return;
}
