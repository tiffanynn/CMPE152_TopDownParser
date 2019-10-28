#include "Lexer.h"
#include "Parser.h"
int main()
{
	Lexer* l = new Lexer();
	ifstream fin;
	fin.open("test2.txt");
	Parser p(l, fin);
	p.program(fin);
}