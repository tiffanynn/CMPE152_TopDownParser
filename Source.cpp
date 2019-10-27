#include "Lexer.h"
#include <vector>
int main()
{

	ifstream fin;
	Lexer lex;
	fin.open("test.txt");
	Word* wp;
	wp = lex.words["int"];
	while (!fin.fail())
	{
		Token* t= lex.scan(fin);
		cout <<  t->toString()<< '\t'<< t->t.printmap[t->tag]  << endl;
	}
	cout << lex.line << endl;
	fin.close();



}

/*
TO DO
------
1) fix virtual function for Num.toString()

*/