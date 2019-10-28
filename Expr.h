#pragma once
#include "Lexer.h"
#include "Type.h"
#include "Node.h"

class Expr :public Node
{
public:
	Token *tok;
	Type* type;
	Expr();
	Expr(Token*, Type*);
	string getNodeStr();
};
Expr::Expr()
{
	tok = new Word();
	type = NULL;
}
Expr::Expr(Token *t, Type* typ)
{
	tok = t;
	type = typ;
}

string Expr::getNodeStr()
{
	string s;
	s = "Token " + tok->toString();
	return s;
}