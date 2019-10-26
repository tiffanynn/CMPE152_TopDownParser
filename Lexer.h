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
	unordered_map<string, Word*> words; // keeps track of variables, maps the string (variable name) to word(token version of variable name)
	int line;
	Tag tag;
	void readchar(ifstream& in);
	bool nextchar(ifstream& in, char);
	Token* scan(ifstream& in);
	void reserve(Word*);
	bool check_char(char);

};
Lexer::Lexer()
{
	peek = ' ';
	line = 1;
	reserve(new Word("if", tag.IF));
	reserve(new Word("else", tag.ELSE));
	reserve(new Word("do", tag.DO));
	reserve(new Word("break", tag.BREAK));
	reserve(new Word("true", tag.TRUE));
	reserve(new Word("false", tag.FALSE));
	reserve(new Word("while", tag.WHILE));
	reserve(new Word("int", tag.INT));
	reserve(new Word("bool", tag.BOOL));
	reserve(new Word("#", tag.MYEOF));



}
bool Lexer::check_char(char c)
{
	if (c == ' ' || c == '(' || c == ' ' || c == '+' || c == '=' || c == '-' ||
		c == ')' || c == '\t' || c == '\n' || c == '}' || c== '/'
		)
		return true;
	else return false;
}
void Lexer::reserve(Word *w)
{
	words[w->lexeme] = w;
	//cout << "Word " << w->lexeme << " reserved with tag: " << w->tag << endl;
}
void Lexer::readchar(ifstream& in)
{
	in >> noskipws >>peek;
}

bool Lexer::nextchar(ifstream& in, char prev)
{
	readchar(in);
	if (peek == prev)
	{
		peek = ' ';
		return true;
	}
	else
	{
		peek = ' ';
		return false;
	}
}


Token* Lexer::scan(ifstream& in)
{
	for (;; readchar(in))
	{
		if (peek == ' ' || peek == '\t') continue;
		else if (peek == '\n')
		{
			line += 1;
			//continue;
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
		else return new Token('&');
		break;
	}
	case '|': 
	{
		if (nextchar(in, '|'))
		{
			return new Word("||", tag.OR);
		}
		else return new Token('|');
		break;
	}
	case '=':
	{
		if (nextchar(in, '='))
		{
			return new Word("==", tag.EQ);
		}
		else return new Token('=');
		break;
	}
	case '!':
	{
		if (nextchar(in, '='))
		{
			return new Word("!=", tag.NE);
		}
		else return new Token('!');
		break;
	}
	case '<':
	{
		if (nextchar(in, '='))
		{
			return new Word("<=", tag.LE);
		}
		else return new Token('<');
		break;
	}
	case '>':
	{
		if (nextchar(in, '='))
		{
			Word w(">=", tag.GE);
			return new Word(">=", tag.GE);
		}
		else return new Token('>');
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
		if (peek != '.') //If there's no decimal point, return a num
		{
			s >> v;
			return new Num(v);
		}
		float x = (float)v; //If there is, return a real token
		stringstream f;
		f << x;
		f << peek;
		readchar(in);
		f << peek;
		while (isdigit(peek) > 0)
		{
			readchar(in);
			f << peek; 
		}
		f >> x;
		return new Real(x);
	}
	if (isalpha(peek) > 0)
	{
		stringstream s;
		s << peek;
		while (isalpha(peek) > 0)
		{
			readchar(in);
			if (check_char(peek)) break;
			s << peek;
		}
		Word* w = words[s.str()]; // This will check if the word is in the reserved keywords like while, do, break, etc
		if (w != NULL)
		{
			return w;
		}
		Word* varname = new Word(s.str(), tag.ID);
		words[s.str()] = varname; //if it's not a keyword, it's a variable. add the hash table using variable name, s.str(), to word with appropriate tag.
		return varname;
	}
	char c = peek;
	peek = ' ';
	return new Token(c);
	




}