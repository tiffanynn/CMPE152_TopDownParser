#pragma once
#include "Node.h"
#include "Block.h"
class Prog : public Node
{
public:
	Block block;
	Prog(Block blk);
	string getNodeStr();
};

Prog::Prog(Block blk)
{
	block = blk;
	children.push_back(block);
}

string Prog::getNodeStr()
{
	return "PROG";
}