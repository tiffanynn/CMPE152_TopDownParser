#include "logic.h"
class And: public Logic{
    public:
    Token something;
    Expr p1, p2;
    And(Token tok, Expr x1, Expr x2);
    string getNodeStr();
};

And::And(Token tok, Expr x1, Expr x2){
    something = tok; 
    p1 = x1;
    p2 = x2;
}

string And::getNodeStr(){
    return "AND";
}
