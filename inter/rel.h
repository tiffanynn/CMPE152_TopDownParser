#include "logic.h"
#include "../symbols/type.h"

using namespace std;

class Rel: public Logical {
    public:
    Rel(){}
    Rel(Token tok, Expr x1, Expr x2);
    Type check(Type p1, Type p2);
};

Type Rel::check(Type p1, Type p2){
    if(p1 == p2){ //needs overloaded operator? idk
        return this->Type.Bool();
    }
    else
    {
        return NULL;
    }
    return 0;
}
