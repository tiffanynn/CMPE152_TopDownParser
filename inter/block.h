#pragma once
#include "stmt.h"
#include <string>
class Block : public Stmt
{
public:
	Stmt *stmt;
	Block(Stmt* s);
	string getNodeStr();
};

Block::Block(Stmt *s)
{
	stmt = s;
	this->children.push_back(stmt);
}

string Block::getNodeStr()
{
	return "BLOCK";
}