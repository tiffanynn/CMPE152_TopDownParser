#pragma once
#include "Stmt.h"
#include "Expr.h"

class Else :public Stmt
{
public:
	Expr* expr;
	Stmt* stmt1, * stmt2;

	Else(Expr*, Stmt*, Stmt*);
	string getNodeStr();
};


Else::Else(Expr* e, Stmt* s1, Stmt* s2)
{
	expr = e;
	stmt1 = s1;
	stmt2 = s2;
	if (expr->type != Type::get_Bool())
		expr->error("Bool required in if");
	children.push_back(expr);
	children.push_back(stmt1);
	children.push_back(stmt2);
}

string Else::getNodeStr()
{
	return "IF-ELSE";
}
