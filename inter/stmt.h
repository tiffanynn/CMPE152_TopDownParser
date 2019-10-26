#pragma once
#include "node.h"

class Stmt : public Node
{
public:
	Stmt();
	Stmt* Null;
	Stmt* Enclosing;
	int after;
};
Stmt::Stmt()
{
	Null = new Stmt;
	after = 0;
	Enclosing->Null;
}