#pragma once
#include "Num.h"
#include "Real.h"
#include "Word.h"
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
	Token* scan(ifstream& in);
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


Token* Lexer::scan(ifstream& in)
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
			return new Word("&&", tag.AND);

		}
		break;
	}
	case '|': 
	{
		if (nextchar(in, '|'))
		{
			return new Word("||", tag.OR);
		}
		break;
	}
	case '=':
	{
		if (nextchar(in, '='))
		{
			return new Word("==", tag.EQ);
		}
		break;
	}
	case '!':
	{
		if (nextchar(in, '='))
		{
			return new Word("!=", tag.NE);
		}
		break;
	}
	case '<':
	{
		if (nextchar(in, '='))
		{
			return new Word("<=", tag.LE);
		}
		break;
	}
	case '>':
	{
		if (nextchar(in, '='))
		{
			Word w(">=", tag.GE);
			return new Word(">=", tag.GE);
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
			return new Num(v);
		}
	}

	return new Token(peek);




}