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
	static Word* get_True()
	{
		static Word* True = new Word("true", 274);
		return True;
	}
	static Word* get_False()
	{
		static Word* False = new Word("false", 262);
	}
	string toString();
};

Word::Word()
{
	lexeme = "ERROR";
	this->tag = t.ERROR;
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