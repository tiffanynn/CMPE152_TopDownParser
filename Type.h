#pragma once
#include "Word.h"

class Type :public Word
{
public:
	int width; //used for storage allocation, but i don't wanna worry about this
	Type();
	Type(string, int, int);
	Tag t;
	static const Type* tester;
	//use the get fucntions to acess reserved types
	static Type* Int, * Char, * Bool, * Float;
	static Type* get_Int() {
		return Int;
	}
	static Type* get_Char()
	{
		return Char;
	}
	static Type* get_Bool()
	{
		return Bool;
	}
	static Type* get_Float()
	{
		return Float;
	}

	bool isitnumeric(Type*);
	Type* max(Type*, Type*);
};
Type::Type()
{
	this->lexeme = "ERROR";
	this->tag = 999;
	width = 0;
}
Type::Type(string s, int tag, int w)
{
	this->lexeme = s;
	this->tag = tag;

	width = w;
}



bool Type::isitnumeric(Type* p)
{
	if (p == get_Char() || p == get_Int() || p == get_Float())
		return true;
	else 
		return false;
}

Type* Type::max(Type* p1, Type* p2)
{
	if (!isitnumeric(p1) || !isitnumeric(p2))
		return NULL;
	else if (p1 == get_Float() || p2 == get_Float()) {
	
		return get_Float();
	}
	else if (p1 == get_Int() || p2 == get_Int())
	{
		return get_Int();
	}
	else return get_Char();

}