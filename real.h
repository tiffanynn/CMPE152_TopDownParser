#pragma once
#include "token.h"
#include "tag.h"

class Real : public Token
{
public:
	Tag t; //this field is used purely to access the values in tag.
	float value;
	Real();
	Real(float v);
	string toString();
};
Real::Real()
{
	this->tag = t.ERROR;
	value = t.ERROR;
}
Real::Real(float v)
{
	this->tag = t.REAL;
	value = v;
}

string Real::toString()
{
	stringstream s;
	s << value;
	return s.str();
}