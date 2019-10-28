#pragma once
#include "Token.h"
#include "Type.h"
#include "Expr.h"

class Logical :public Expr
{
public:
	Expr* expr1, *expr2;
	Logical(Token* tp, Expr* e1, Expr* e2);
	Type* check(Type*, Type*);
};

Logical::Logical(Token* tp, Expr* e1, Expr* e2)
{
	this->tok = tp;
	this->type = NULL;
	expr1 = e1;
	expr2 = e2;
}

Type* Logical::check(Type* t1, Type* t2)
{
	if (t1 == t1->get_Bool() && t2 == t2->get_Bool())
	{
		return t1->get_Bool();
	}
	else return NULL;
}
