#pragma once
#include "Num.h"
#include "Type.h"
#include "Expr.h"

class Constant :public Expr
{
public:
	Constant(Token*, Type*);
	Constant(int i);
	static Constant* True;
	static Constant* False;
	static Constant* get_True()
	{
		return True;
	}
	static Constant* get_False()
	{
		return False;
	}
	string getNodeStr();

};

Constant::Constant(Token* t, Type* t2)
{
	this->tok = t;
	this->type = t2;
}

Constant::Constant(int i)
{
	this->tok = new Num(i);
	this->type = Type::get_Int();
}

string Constant::getNodeStr()
{
	return ("Token " + tok->toString());
}

