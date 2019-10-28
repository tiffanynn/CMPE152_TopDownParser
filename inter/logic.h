#include "expr.h"
#include "../symbols/type.h"
using namespace std;

class Logic:public Expr{
 public:
 Expr expr1, expr2;
 Logic(){}
 Logic(Token tok, Expr x1, Expr x2);
 Type check(Type p1, Type p2);
 void operator=(Expr const &e1);
};


void Logic::operator=(Expr const &e1){
    
}
Logic::Logic(Token tok, Expr x1, Expr x2){
    this->tok = NULL;
    expr1 = x1;
    expr2 = x2;
   Type type = check(expr1.type, expr2.type); 
    if(type = NULL){
        cout << "Type error" << endl;
    }
    children.push_back(expr1); //couldn't identify "children" vector
    children.push_back(expr2);
}