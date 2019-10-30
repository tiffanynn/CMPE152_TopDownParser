#pragma once
#include "Stmt.h"
#include "Id.h"

class Set : public Stmt
{
public:
	Id* id;
	Expr* expr;
	Set(Id*, Expr*);
	string getNodeStr();
	Type* check(Type* t1, Type* t2);
};

Set::Set(Id* i, Expr* e)
{
	id = i;
	expr = e;
	if (check(id->type, expr->type) == NULL)
	{
		error("Type error in set");
	}
	children.push_back(id);
	children.push_back(expr);
}


Type* Set::check(Type* t1, Type* t2)
{
	if (t1->isitnumeric(t1) && t2->isitnumeric(t2))
		return t2;
	else if (t1 == Type::get_Bool() && t2 == Type::get_Bool())
		return t2;
	else return NULL;
}

string Set::getNodeStr()
{
	return "ASSIGN";
}