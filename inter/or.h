#pragma once
#include "Logic.h"
#include "Expr.h"

class Or :public Logical
{
public:
	Or(Token* t, Expr* e1, Expr *e2);
	string getNodeStr();
};

Or::Or(Token* t, Expr* e1, Expr* e2)
{
	this->tok = t;
	this->expr1 = e1;
	this->expr2 = e2;
}

string Or::getNodeStr()
{
	return "OR";
}