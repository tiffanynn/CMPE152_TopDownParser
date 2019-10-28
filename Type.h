#pragma once
#include "Word.h"

class Type :public Word
{
public:
	int width; //used for storage allocation, but i don't wanna worry about this
	Type();
	Type(string, int, int);
	Tag t;

	//use the get fucntions to acess reserved types

	static Type* get_Int() {
		static Type* Int = new Type("int", 257, 4);
		return Int;
	}
	static Type* get_Char()
	{
		static Type *Char = new Type("char", 257, 1);
		return Char;
	}
	static Type* get_Bool()
	{
		static Type* Bool = new Type("bool", 257, 1);
		return Bool;
	}
	static Type* get_Float()
	{
		static Type* Float = new Type("float", 257, 8);
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