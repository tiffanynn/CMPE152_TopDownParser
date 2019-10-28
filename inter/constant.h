#pragma once
#include "../lexer/num.h"
#include "../symbols/type.h"
#include "expr.h"

class Constant :public Expr
{
public:
	Constant(Token*, Type*);
	Constant(int i);
	static Constant* get_True()
	{
		static Constant* True = new Constant(Word::get_True(), Type::get_Bool());
		return True;
	}
	static Constant* get_False()
	{
		static Constant* False = new Constant(Word::get_False(), Type::get_Bool());
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