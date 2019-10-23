#pragma once
#include "Stmt.h"
#include <string>
class Block : public Stmt
{
public:
	Stmt stmt;
	Block(Stmt s);
	string getNodeStr();
};

Block::Block(Stmt s)
{
	stmt = s;
	children.push_back(stmt);
}

string Block::getNodeStr()
{
	return "BLOCK";
}