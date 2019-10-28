#pragma once
#include "../lexer/lexer.h"
#include "../symbols/type.h"
#include "id.h"
#include "stmt.h"
#include "expr.h"

using namespace std;

class Set:public Stmt{
    Id i1;
    Expr e1;
    Set(){}
    Set(Id i, Expr x);
    string getNodeStr();
    Type check(Type p1, Type p2);
};