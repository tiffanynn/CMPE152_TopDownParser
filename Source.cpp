#include "Lexer.h"
#include <vector>
int main()
{

	ifstream fin;
	Lexer lex;
	fin.open("test2.txt");
	Word* wp;
	wp = lex.words["int"];
	while (!fin.fail())
	{
		Token* t= lex.scan(fin);
		if (t->tag == 420) {
			cout << t->toString() << '\t' << t->t.printmap[t->tag] << endl;
			break;
		}
		if (t->tag == 999) {
			cout << t->toString() << '\t' << t->t.printmap[t->tag] << endl;
			break;
		}
		cout <<  t->toString()<< '\t'<< t->t.printmap[t->tag]  << endl;
	}
	fin.close();


}

/*
TO DO
------
1) fix virtual function for Num.toString()

*/