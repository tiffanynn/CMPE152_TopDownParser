#pragma once
#include "../symbols/type.h"
#include "stmt.h"
#include "expr.h"

using namespace std;

class If:public Stmt{
    public:
    Expr e1;
    Stmt s1;
    If();
    If(Expr x, Stmt s);
    string getNodeStr();
};

If::If(){
    //do we need to initialize them?
    expr = NULL;
    stmt = NULL;
}

If::If(Expr x, Stmt s){
    expr = x;
    stmt = s;
    if(expr.type != this->Type.get_Bool()){
        cout << "Boolean required in while";
    }
    else{
        this->children.push_back(expr);
        this->children.push_back(stmt);
    }
}

string If::getNodeStr(){
    return "IF";
}