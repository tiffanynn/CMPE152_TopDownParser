#pragma once
#include "stmt.h"

using namespace std;

class Break:public Stmt{
    public:
    Stmt s1;
    Break();
    string getNodeStr();
};

Break::Break(){
    if(s1.Enclosing == s1.Null){
        cout << "unenclosed break";
    }
    s1 = s1.Enclosing; //error
}

string Break::getNodeStr(){
    return "BREAK";
}