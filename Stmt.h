#pragma once
#include "Node.h"

class Stmt :public Node
{
public:
	Stmt();
	static Stmt* Null;
	static Stmt* Enclosing;
	static Stmt* get_Null()
	{
		static Stmt* Null = new Stmt();
		return Null;
	}

	static Stmt* get_Enclosing()
	{
		static  Stmt* Enclosing = Stmt::get_Null();
		return Enclosing;
	}

	int after; //saves tag after?
	//Stmt* Enclosing;
};

Stmt::Stmt()
{
	after = 0;
}