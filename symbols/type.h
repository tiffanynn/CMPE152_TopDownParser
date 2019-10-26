#include "../lexer/token.h"
#include "string.h"
using namespace std;


class Type:public Word{
    public:
    int width = 0;
    Type::Type(){}
    Type(string s, int tag, int w){
    this->s = tag; //idk what this is
    width = w; 
    }
   static Type Int()
    {
        Type comp;
        comp.value = "int";
        comp.tokenTag = "BASE_TYPE";
        return comp;
    };
   
    bool numeric(Type p);
    Type max(Type p1, Type p2);



};

bool Type::numeric(Type p){
    if(p == Type.Char || p == Type.Int){
        return true;
    }
    else if(p == Type.Float){
        return true;
    }
    else{
        return false;
    }
    return 0;
}

Type Type::max(Type p1, Type p2){
    if(!numeric(p1)|| !numeric(p2)){
        return NULL;
    }
    else if(p1 == Type.Float || p2 == Type.Int){
        return Type.Float;
    }
    else if(p1 == Type.Int || p2 == Type.Int){
        return Type.Int;
    }
    else{
        return Type.Char;
    }
}
