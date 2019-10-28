#pragma once
#include "../symbols/type.h"
#include "stmt.h"
#include "expr.h"

using namespace std;

class While:public Stmt{
    public:
    Expr e1;
    Stmt s1;
    While();
    void init(Expr x, Stmt s);
    string getNodeStr();
};

While::While(){
    //do we need to initialize them?
    expr = NULL;
    stmt = NULL;
}

void While::init(Expr x, Stmt s){
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

string While::getNodeStr(){
    return "WHILE";
}