#pragma once
#include "Token.h"
#include "Tag.h"

class Real : public Token
{
public:
	Tag t; //this field is used purely to access the values in tag.
	float value;
	Real();
	Real(float v);
	string toString();
};
Real::Real() //default consructor should never be called
{
	this->tag = Tag::ERROR;
	value = Tag::ERROR;
}
Real::Real(float v)
{
	this->tag = Tag::REAL;
	value = v;
}

string Real::toString()
{
	stringstream s;
	s << value;
	return s.str();
}