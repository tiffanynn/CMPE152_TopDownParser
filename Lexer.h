#pragma once
#include "Num.h"
#include "Real.h"
#include "Word.h"
#include "Type.h"
#include <unordered_map>
#include <stack>
#include <fstream>

Word* Word::True = new Word("true", 274);
Word* Word::False = new Word("false", 262);
Type* Type::Int = new Type("int", 257, 4);
Type* Type::Char = new Type("char", 257, 1);
Type* Type::Bool = new Type("bool", 257, 1);
Type* Type::Float = new Type("float", 257, 8);

int Tag::AND = 256, Tag::BASE_TYPE = 257, Tag::BREAK = 258, Tag::DO = 259, Tag::ELSE = 260, 
Tag::EQ = 261, Tag::FALSE = 262, Tag::ID = 264, Tag::IF = 265, Tag::NUM = 270, Tag::OR = 271, 
Tag::TRUE = 274, Tag::WHILE = 275, Tag::MYEOF = 420, Tag::ERROR = 999, Tag::REAL = 272,
Tag::INT = 276, Tag::BOOL = 278, Tag::TEMP = 273, Tag::NE = 269, Tag::GE = 263, Tag::LE = 267;

class Lexer
{
public:
	Lexer();
	char peek;
	unordered_map<string, Word*> words; // keeps track of variables, maps the string (variable name) to word(token version of variable name)
	unordered_map<int, Type*> get_type;
	int line;
	Tag tag;
	void readchar(ifstream&);
	bool nextchar(ifstream&, char);
	Token* scan(ifstream&);
	Word *last_word;
	void reserve(Word*);
	bool check_char(char);
	bool check_acceptable_words(string);

};
Lexer::Lexer()
{
	peek = ' ';
	line = 1;
	reserve(new Word("if", Tag::IF));
	reserve(new Word("else", Tag::ELSE));
	reserve(new Word("do", Tag::DO));
	reserve(new Word("int", Tag::INT));
	reserve(new Word("break", Tag::BREAK));
	reserve(new Word("while", Tag::WHILE));
	reserve(new Word("#", Tag::MYEOF));
	reserve(Word::False);
	reserve(Word::True);
	reserve(Type::Int);
	reserve(Type::Float);
	reserve(Type::Char);
	reserve(Type::Bool);

	//get_type[270] = Type::BASE_TYPE;
	//get_type[257] = Type::Int;
	get_type[276] = Type::Int;
	get_type[277] = Type::Float;
	get_type[274] = Type::Bool;
	get_type[262] = Type::Bool;



}
bool Lexer::check_acceptable_words(string s)
{
	if (s == "while" || s == "if" || s == "do" || s == "else" || s == "int" || s == "bool" || s == "float" ) //
		return true;
	else return false;
}
bool Lexer::check_char(char c) //helper function to not have scan() do crazy stuff when peek is looking at a terminal
{
	if (c == ' ' || c == '+' || c == '=' || c == '-' || c == '(' ||
		c == ')' || c == '\t' || c == '\n' || c == '}' || c== '/' || c == ';'
		)
		return true;
	else return false;
}
void Lexer::reserve(Word *w)
{
	words[w->lexeme] = w;
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


Token* Lexer::scan(ifstream& in) // the getnextToken() function. Most of the lexer processing logic is here.
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
		if (nextchar(in, '&')) //if the next character is the same as peek, then return the correct correct tag
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
	case '(':
	{
		return new Token('(');
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
		if (peek != '.') //If there's no decimal point, return a Num, If there is, return a Real
		{
			s >> v;
			return new Num(v);
		}
		float x = (float)v; 
		stringstream f;
		f << x;
		f << peek;
		readchar(in);
		f << peek; //get the decimal point
		while (isdigit(peek) > 0) //get the last fraction
		{
			readchar(in);
			f << peek; 
		}
		f >>x;
		return new Real(x); //return Real aka floats
	}
	if (isalpha(peek) > 0) //handle alphabetic characters
	{
		stringstream s;
		s << peek;
		while (isalpha(peek) > 0) //read the next character and check peek
		{
			readchar(in);
			if (check_char(peek)) break; //if peek is looking at a terminal or weird symbol, break out of the loop and don't append it to the string.
			s << peek;
		}
		Word* w = words[s.str()]; // This will check if the word is in the reserved keywords like while, do, break, etc
		if (w != NULL)
		{
			last_word = w;
			return w;
		}
		//if(last_word->lexeme != )
		if (!check_acceptable_words(last_word->lexeme))
			return new Word; //this should have the error information
		Word* varname = new Word(s.str(), tag.ID);
		words[s.str()] = varname; //if it's not a keyword, it's a variable. add the hash table using variable name, s.str(), to word with appropriate tag.
		last_word = varname;
		return varname;
	}
	char c = peek;
	if (c == '#')
	{
		peek = ' ';
		return words["#"]; //return reserved eof token
	}
	peek = ' ';
	return new Token(c);
	

}
