#pragma once
#include "node.h"

class Stmt :public Node
{
public:
	Stmt();
	Stmt* Null;
	int after; //saves tag after?
	Stmt* Enclosing;
};

Stmt::Stmt()
{
	Null = NULL;
	Enclosing = this->Null;
	after = 0;
}