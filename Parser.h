#pragma once
#include "Lexer.h"
#include "Block.h"
#include "Env.h"
#include "Prog.h"
class Parser
{
private:
	Lexer* lex;
	Token* look;
public:
	Env* top;
	string filename;
	ifstream* in;
	int used;
	Parser();
	Parser(Lexer* l, ifstream&);
	void move(ifstream&);
	void error(string);
	void match(int t, ifstream&);
	Prog* program(ifstream& in);
	Block* block(ifstream&);
	void decls();
	Type* type();
	Stmt* stmts();
	Stmt* stmt();
	Stmt* assign();
};
Parser::Parser()
{
	in = NULL;
	lex = NULL;
	look = NULL;
	top = NULL;
	used = 0;
}
Parser::Parser(Lexer* l, ifstream& in)
{
	lex = l;
	move(in);
}
void Parser::error(string s)
{
	cout << "Error near line " << lex->line << ": " << s;
}

void Parser::match(int t,ifstream& in)
{
	if (look->tag == t)
	{
		move(in);
	}
	else
		error("syntax error");
}
Block* Parser::block(ifstream& in)
{
	match('{', in);
	Env* savedenv = top; //save current scope
	top = new Env(top);
	decls();
	Stmt* s = stmts();
	match('}', in);
	top = savedenv;
	return new Block(s);

}

Prog* Parser::program(ifstream& in)
{
	Block* s = block(in);
	return new Prog(s);

}

void Parser::move(ifstream& in)
{
	look = lex->scan(in);
	cout << look->toString() << endl;
}