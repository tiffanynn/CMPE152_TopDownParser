#pragma once
#include "Expr.h"


class Id : public Expr
{
public:
	int offset;
	Id();
	Id(Word*, Type*, int);
};
Id::Id()
{
	this->tok = new Word(); //this is the error token
	this->type = NULL;
	offset = 999;
}
Id::Id(Word* wp, Type* tp, int b)
{
	this->tok = wp;
	this->type = tp;
	offset = b;
}