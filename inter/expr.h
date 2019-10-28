#include "node.h"
#include "../symbols/type.h"
using namespace std;

class Expr: public Node{
    public:
    Token op;
    Type type;
    Expr(){}
    Expr(Token tok, Type p);
    string getNodeStr();
};


Expr::Expr(Token tok, Type p){
    op = tok;
    type = p;
}

string Expr::getNodeStr(){
    return "Token" + op.toString();
}