#pragma once
#include "token.h"
#include "tag.h"
class Num :public Token
{
public:
	Tag t;//this field is used purely to access the values in tag.
	int value;
	Num();
	Num(int);
	string toString();
};
Num::Num()
{
	this->tag = t.ERROR;
	value = t.ERROR;
}
Num::Num(int v)
{
	this->tag = t.NUM;
	value = v;
}

string Num::toString()
{
	stringstream s;
	s << value;
	return s.str();
}
