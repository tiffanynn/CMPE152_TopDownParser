#pragma once
#include "node.h"
#include "block.h"
class Prog : public Node
{
public:
	Prog(Block*);
	Block* block;
	string getNodeStr();
};
Prog::Prog(Block *bp)
{
	block = bp;
	this->children.push_back(block);
}

string Prog::getNodeStr()
{
	return "PROGRAM";
}