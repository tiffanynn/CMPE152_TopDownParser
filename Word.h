#pragma once
#include "Tag.h"
#include "Token.h"

class Word : public Token
{
public:
	Tag t;
	string lexeme;
	static Word* True,*False;
	Word();
	Word(string, int);
	static Word* get_True()
	{
		return True;
	}
	static Word* get_False()
	{
		return False;
	}
	string toString();
};

Word::Word()
{
	lexeme = "ERROR";
	this->tag = Tag::ERROR;
}
Word::Word(string s, int te)
{
	this->tag = te;
	lexeme = s;

}

string Word::toString()
{
	return lexeme;
}