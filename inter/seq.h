#pragma once
#include "string.h"
#include "stmt.h"
using namespace std;

class Seq:public Stmt{
    public:
    Stmt stmt1, stmt2;
    Seq();
    Seq(Stmt s1, Stmt s2);
    string getNodeStr();
};


Seq::Seq(){}
Seq::Seq(Stmt s1, Stmt s2){
    stmt1 = s1;
    stmt2 = s2;
    this->children.push_back(stmt1);
    this->children.push_back(stmt2);
}

string Seq::getNodeStr(){
    return "STMTS";
}