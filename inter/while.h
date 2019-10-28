#pragma once
#include "Stmt.h"
#include "Expr.h"
class While :public Stmt
{
public:
	Expr* expr;
	Stmt* stmt;
	While();
	void init(Expr*, Stmt*);
	string getNodeStr();

};

While::While()
{
	expr = NULL;
	stmt = NULL;
}

void While::init(Expr* e, Stmt* s)
{
	expr = e;
	stmt = s;
	if (expr->type != Type::get_Bool())
		expr->error("Bool required in while");
	children.push_back(expr);
	children.push_back(stmt);
}

string While::getNodeStr()
{
	return "WHILE";
}