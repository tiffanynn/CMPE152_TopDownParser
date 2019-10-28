#pragma once
#include "Expr.h"
#include "Token.h"
#include "Type.h"

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