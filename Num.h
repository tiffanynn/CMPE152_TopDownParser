#pragma once
#include "Token.h"
#include "Tag.h"
class Num :public Token
{
public:
	Tag t;//this field is used purely to access the values in tag.
	int value;
	string lexeme;
	Num();
	Num(int);
	string toString();
};
Num::Num() //default consructor should never be called
{
	this->tag = Tag::ERROR;
	value = Tag::ERROR;
	lexeme = "ERROR";
}
Num::Num(int v)
{
	this->tag = Tag::NUM;
	value = v;
	stringstream s;
	s << v;
	lexeme = s.str();
}

string Num::toString() //need to call virtual fu nction correctly
{
	stringstream s;
	s << value;
	return lexeme;
}

