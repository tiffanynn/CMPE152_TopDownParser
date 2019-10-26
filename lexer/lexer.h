#pragma once
#include "num.h"
#include "real.h"
#include "word.h"
#include <unordered_map>
#include <fstream>

class Lexer
{
public:
	Lexer();
	char peek;
	unordered_map<string, Word> words; // keeps track of variables, maps the string (variable name) to word(token version of variable name)
	int line;
	Tag tag;
	void readchar(ifstream& in);
	bool nextchar(ifstream& in, char);
	Token scan(ifstream& in);
};
Lexer::Lexer()
{
	peek = ' ';
	line = 1;
}

void Lexer::readchar(ifstream& in)
{
	in >> noskipws >>peek;
	//cout << peek << endl;
}

bool Lexer::nextchar(ifstream& in, char prev)
{
	char temp;
	in >> noskipws >> temp;
	if (temp == prev)
		return true;
	else 
		return false;
}


Token Lexer::scan(ifstream& in)
{
	for (;; readchar(in))
	{
		if (peek == ' ' || peek == '\t') continue;
		else if (peek == '\n')
		{
			line += 1;
		}
		else break;
	}
	switch (peek)
	{
	case '&':
	{
		if (nextchar(in, '&'))
		{
			Word w("&&", tag.AND);
			return w;
		}
		break;
	}
	case '|': 
	{
		if (nextchar(in, '|'))
		{
			Word w("||", tag.OR);
			return w;
		}
		break;
	}
	case '=':
	{
		if (nextchar(in, '='))
		{
			Word w("==", tag.EQ);
			return w;
		}
		break;
	}
	case '!':
	{
		if (nextchar(in, '='))
		{
			Word w("!=", tag.NE);
			return w;
		}
		break;
	}
	case '<':
	{
		if (nextchar(in, '='))
		{
			Word w("<=", tag.LE);
			return w;
		}
		break;
	}
	case '>':
	{
		if (nextchar(in, '='))
		{
			Word w(">=", tag.GE);
			return w;
		}
		break;
	}
	default:
		break;
	}// end case parenthesis
	if (isdigit(peek) > 0)
	{
		int v = 0;
		stringstream s;
		s << peek;
		while (isdigit(peek) > 0)
		{
			readchar(in);
			s << peek;
		}
		if (peek != '.')
		{
			s >> v;
			Num n(v);
			return n;
		}
	}
	Token t(peek);


	return t;






}