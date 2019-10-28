#pragma once
#include "Stmt.h"
#include "Expr.h"
class If :public Stmt
{
public:

	Expr* expr;
	Stmt* stmt;
	If(Expr* e, Stmt* s);
	string getNodeStr();
};

If::If(Expr* e, Stmt* s)
{
	expr = e;
	stmt = s;
	children.push_back(e);
	children.push_back(s);
}

string If::getNodeStr()
{
	return "IF";
}