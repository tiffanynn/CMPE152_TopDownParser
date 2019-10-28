#pragma once
#include "Stmt.h"
#include <string>
class Break : public Stmt
{
	Stmt* stmt;
	Break();
	string getNodeStr();
};

Break::Break()
{
	if (Stmt::get_Enclosing() == Stmt::get_Null())
		error("unenclosed break");
	stmt = Stmt::get_Enclosing();
}

string Break::getNodeStr()
{
	return "BREAK";
}