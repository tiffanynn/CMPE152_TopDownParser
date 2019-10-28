#pragma once
#include "node.h"
#include "../lexer/lexer.h"
#include "../symbols/type.h"
using namespace std;

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