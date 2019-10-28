#pragma once
#include "Stmt.h"
#include "Expr.h"
class Do :public Stmt
{
public:
	Expr* expr;
	Stmt* stmt;
	Do();
	void init(Stmt*, Expr*);
	string getNodeStr();
};

Do::Do()
{
	expr = NULL;
	stmt = NULL;
}

void Do::init(Stmt* s, Expr* e)
{
	expr = e;
	stmt = s;
	if (expr->type != Type::get_Bool())
		expr->error("Bool required in Do statement");
	children.push_back(expr);
	children.push_back(stmt);
}

string Do::getNodeStr()
{
	return "DO";
}