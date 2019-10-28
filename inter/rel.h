#include "logic.h"
#include "../symbols/type.h"

using namespace std;

class Rel:public Logic{
    public:
    Rel(){}
    Rel(Token tok, Expr x1, Expr x2);
    Type check(Type p1, Type p2);
};

