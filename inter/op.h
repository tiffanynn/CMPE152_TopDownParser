#pragma once
#include "expr.h"
#include "../lexer/token.h"
#include "../symbols/type.h"

class Op :public Expr
{
public:
	Op();
	Op(Token*, Type*);
};
Op::Op() //should never be called
{
	this->tok = new Word(); //returns error token
	this->type = NULL;
}

Op::Op(Token* tp, Type* pp)
{
	this->tok = tp;
	this->type = pp;
}