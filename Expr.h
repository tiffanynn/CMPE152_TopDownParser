#pragma once
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
	void error(string s);
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
void Expr::error(string s)
{
	cout << "Error: " << s << endl;
}