#pragma once
#include "Lexer.h"
#include "Block.h"
#include "Env.h"
#include "Prog.h"
#include "Tag.h"
#include "Seq.h"
#include "If.h"
#include "Else.h"
#include "And.h"
#include "Do.h"
#include "Arith.h"
#include "Rel.h"
#include "Set.h"
#include "While.h"
#include "Constant.h"

Stmt* Stmt::Null = new Stmt();
Stmt* Stmt::Enclosing = Null;
Constant* Constant::True = new Constant(Word::True, Type::Bool);
Constant* Constant::False = new Constant(Word::False, Type::Bool);

class Parser
{
private:
	Lexer* lex;
public:
	Token* look;
	Env* top;
	int used;
	Parser();
	Parser(Lexer* l, ifstream&);
	void move(ifstream&);
	void error(string);
	void match(int t, ifstream&);
	Prog* program(ifstream& in);
	Block* block(ifstream&);
	void decls(ifstream& in);
	Type* type(ifstream& in);
	Expr* andexpr(ifstream& in);
	Expr* equality(ifstream& in);
	Stmt* stmts(ifstream& in);
	Stmt* stmt(ifstream& in);
	Expr* allexpr(ifstream& in);
	Expr* rel(ifstream& in);
	Expr* expr(ifstream& in);
	Expr* term(ifstream& in);
	Expr* factor(ifstream& in);
	Stmt* assign(ifstream& in);
};
Parser::Parser()
{
	//Type* Type::tester = new Type("int", 275, 4);
	lex = NULL;
	look = NULL;
	top = NULL;
	used = 0;
}
Parser::Parser(Lexer* l, ifstream& in)
{
	lex = l;
	move(in);
	used = 0;
}
void Parser::error(string s)
{
	cout << "Error near line " << lex->line << ": " << s;
}

void Parser::match(int t,ifstream& in)
{
	if (look->tag == t)
	{
		if (look->tag == Type::Int->tag)
		{
			cout << "This is happening correctly look tag:  " << look->tag << endl;
		}
		move(in);
	}
	else
	{
		error("syntax error\n");
		cout << "error's tag: " << look->tag << endl;
		cout << "error info: " << look->toString() << endl;
	}
}
Block* Parser::block(ifstream& in)
{
	cout << "block" << endl;
	match('{', in);
	Env* savedenv = top; //save current scope
	top = new Env(top);
	decls(in);
	cout << "After decl()" << endl;
	Stmt* s = stmts(in);
	match('}', in);
	top = savedenv;
	return new Block(s);

}

Prog* Parser::program(ifstream& in)
{
	cout << "prog" << endl;
	Block* s = block(in);
	return new Prog(s);
}

void Parser::move(ifstream& in)
{
	look = lex->scan(in);
}

void Parser::decls(ifstream& in)
{
	cout << "decls" << endl;
	while (look->tag == Tag::BASE_TYPE)
	{
		Type* p = type(in);
		cout << "after type()" << endl;
		Token* t = look; 
		match(Tag::ID, in);
		match(';', in);
		Id* id = new Id((Word*)t, p, used);
		top->put(t, id);
		used += p->width;
	}

}

Stmt* Parser::stmts(ifstream& in)
{
	cout << "stmts" << endl;
	if (look->tag == '}')
	{
		cout << "stmts() tag = }?" << endl;
		return Stmt::Null;
	}
	else
	{
		Stmt* s = stmt(in);
		return new Seq(s, stmts(in));
	}

}

Stmt* Parser::stmt(ifstream& in)
{
	cout << "stmt" << endl;
	Expr* expr;
	Stmt* s, *s1, *s2;
	Stmt* savedstmt;
	int IF = lex->words["if"]->tag;
	switch (look->tag)
	{
	case ';':
	{
		move(in);
		cout << "stmt's semicolon case" << endl;
		return Stmt::Null;
	}
	case 265: //IF tag. Can't use static declaration because it isn't constant.
	{
		match(Tag::IF, in);
		match('(', in);
		expr = allexpr(in);
		match(')', in);
		s1 = stmt(in);
		if (look->tag != Tag::ELSE)
			return new If(expr, s1);
		match(Tag::ELSE,in);
		s2 = stmt(in);
		return new Else(expr, s1, s2);
	}
	case 275: //WHILE tag.
	{
		While* whilenode = new While();
		savedstmt = Stmt::Enclosing;
		Stmt::Enclosing = whilenode;
		match(Tag::WHILE, in);
		match('(', in);
		expr = allexpr(in);
		match(')', in);
		s1 = stmt(in);
		whilenode->init(expr, s1);
		Stmt::Enclosing = savedstmt;//reset enclosing static member
		return whilenode;
	}

	case 259://DO tag.
	{
		Do* donode = new Do();
		savedstmt = Stmt::Enclosing;
		Stmt::Enclosing = donode;
		match(Tag::DO, in);
		s1 = stmt(in);
		match(Tag::WHILE, in);
		match('(', in);
		expr = allexpr(in);
		match(')', in);
		donode->init(s1, expr);
		Stmt::Enclosing = savedstmt; //reset Enclosing
		return donode;
	}
	case 258: //BREAK tag
	{
		match(Tag::BREAK, in);
		match(';', in);
	}
	case '{':
	{
		return block(in);
	}
	default:
		return assign(in);

	}
}
Expr* Parser::allexpr(ifstream& in)
{
	cout << "allexpr" << endl;
	Expr* expr = andexpr(in);
	cout << "after andexpr" << endl;
	while (look->tag == Tag::OR)
	{
		Token* t = look;
		move(in);
		expr = new Or(t, expr, andexpr(in));
	}
	return expr;
}

Expr* Parser::andexpr(ifstream& in)
{
	cout << "andexpr" << endl;
	Expr* x = equality(in);
	cout << "after eq" << endl;
	while (look->tag == Tag::AND)
	{
		Token* t = look;
		move(in);
		x = new And(t, x, equality(in));
	}
	return x;
}

Expr* Parser::equality(ifstream& in)
{
	cout << "eq" << endl;
	Expr* x = rel(in);
	cout << "after rel" << endl;
	while (look->tag == Tag::EQ || look->tag == Tag::NE)
	{
		Token* t = look;
		move(in);
		x = new Rel(t, x, rel(in));
	}
	return x;
}
Expr* Parser::rel(ifstream& in) //troubling function
{
	cout << "rel" << endl;
	Expr* x = expr(in);
	cout << "after expr" << endl;
	switch (look->tag)
	{
	case '<': case 267: case 263: case '>':
	{
		Token* t = look;
		move(in);
		x = new Rel(t, x, expr(in));
	}
	default:
		return x;
	}
}

Expr* Parser::expr(ifstream& in)
{
	cout << "expr" << endl;
	Expr* x = term(in);
	while (look->tag == '+' || look->tag == '-')
	{
		Token* t = look;
		move(in);
		x = new Arith(t, x, term(in));
	}
	return x;
}

Expr* Parser::term(ifstream& in)
{
	cout << "term" << endl;
	Expr* x = factor(in);
	
	while (look->tag == '*' || look->tag == '/')
	{
		Token* t = look;
		move(in);
		x = new Arith(t, x, factor(in));
	}
	//return x;
	return new Expr();
}

Type* Parser::type(ifstream& in)
{
	cout << "Type" << endl;
	//Type* p = lex->get_type[look->tag];
	Type* p = (Type*)look;
	//move(in);
	match(Tag::BASE_TYPE, in);
	return p;
}

Stmt* Parser::assign(ifstream& in)
{
	cout << "assign" << endl;
	Stmt* stmt;
	Token* t = look;
	match(Tag::ID,in);
	Id* id = top->get(t);
	if (id == NULL)
	{
		error(t->toString() + " undeclared");
	}
	move(in);
	stmt = new Set(id, allexpr(in));
	match(';', in);
	return stmt;
}

Expr* Parser::factor(ifstream& in)
{
	cout << "factor" << endl;
	Expr* x = NULL;
	switch(look->tag)
	{
	case '(':
	{
		move(in);
		x = allexpr(in);
		match(')', in);
		return x;
	}
	case 270: //NUM tag
	{
		x = new Constant(look, Type::Int);
		move(in);
		return x;
	}
	case 272: //REAL
	{
		x = new Constant(look, Type::Float);
		move(in);
		return x;
	}
	case 274: // TRUE
	{
		x = Constant::True;
		return x;
	}
	case 262: //FALSE 
	{
		x = Constant::False;
		return x;
	}
	case 264: //ID
	{
		cout << "factor id branch" << endl;
		string s = look->toString();
		Id* id = top->get(look);
		if (id == NULL);
		{
			error(look->toString() + " undeclared");
		}
		move(in);
		return id;
	}
	default:
	{
		error("factor syntax error");
		return x;
	}
	}
}

