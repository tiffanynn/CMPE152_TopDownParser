#pragma once
#include <iostream>
#include "Tag.h"
#include <sstream>
#include <string>
using namespace std;
class Token
{
public:
	Tag t; //this field is used purely to access the values in tag.
	Token();
	Token(int);
	int tag;
	virtual string toString();
	void operator= (Token const &t2);
};
Token::Token()
{
	tag = t.ERROR;
}
Token::Token(int t)
{
	tag = t;
}

string Token::toString()
{
	if (tag == 999)
	{
		return "ERROR";
	}
	else
	{
		stringstream s;
		s << (char)tag;
		return s.str(); //for default values like ;
	}
}

void Token::operator=(Token const &t2){
	tag= t2.tag;
	
}
