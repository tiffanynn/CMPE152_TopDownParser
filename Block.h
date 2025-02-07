#pragma once
#include "Stmt.h"
#include <string>
class Block : public Stmt
{
public:
	Stmt *stmt;
	Block();
	Block(Stmt* s);
	string getNodeStr();
};
Block::Block()
{
	stmt = NULL;
}
Block::Block(Stmt *s)
{
	stmt = s;
	this->children.push_back(stmt);
}

string Block::getNodeStr()
{
	return "BLOCK";
}