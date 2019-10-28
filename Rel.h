#pragma once
#include "Logical.h"


class Rel : public Logical
{
public:
	Rel();
	Rel(Token*, Expr*, Expr*);
	Type* check(Type*, Type*);

};
Rel::Rel()
{
	this->tok = new Word();
	this->expr1 = NULL;
	this->expr2 = NULL;
}
Rel::Rel(Token* t, Expr* e1, Expr* e2)
{
	this->tok = t;
	this->expr1 = e1;
	this->expr2 = e2;
}

Type* Rel::check(Type* t1, Type* t2)
{
	if (t1 == t2) return Type::get_Bool();
	else return NULL;
}
