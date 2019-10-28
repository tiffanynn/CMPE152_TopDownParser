#pragma once
#include "Logical.h"

class And :public Logical
{
public:
	And(Token*, Expr*, Expr*);
	string getNodeStr();
};

And::And(Token* t, Expr* e1, Expr* e2)
{
	this->tok = t;
	this->expr1 = e1;
	this->expr2 = e2;
}

string And::getNodeStr()
{
	return "AND";
}