#pragma once
#include "Tag.h"
#include "Token.h"

class Word : public Token
{
public:
	Tag t;
	string lexeme;
	Word();
	Word(string, int);
	string toString();
};

Word::Word()
{
	lexeme = "ERROR";
	this->tag = t.ERROR;
}
Word::Word(string s, int te)
{
	this->tag = t.ID;
	lexeme = s;
}

string Word::toString()
{
	return lexeme;
}