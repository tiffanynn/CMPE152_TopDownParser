#pragma once
#include "Op.h"

class Arith : public Op
{
public:
	Type TINFO;
	Expr* expr1, * expr2;
	Arith(Token*, Expr*, Expr*);
	string getNodeStr();
};

Arith::Arith(Token* t, Expr* e1, Expr* e2)
{
	this->tok = t;
	this->type = NULL;
	expr1 = e1;
	expr2 = e2;
	Type* typ = TINFO.max(e1->type, e2->type); 
	if (typ == NULL)
		error("type error");
	children.push_back(expr1);
	children.push_back(expr2);
}

string Arith::getNodeStr()
{
	string s = "Token " + tok->toString();
	return s;
}