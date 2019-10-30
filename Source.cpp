#include "Lexer.h"
#include "Or.h"
#include "Break.h"
#include "Parser.h"
int main()
{

	
	ifstream fin;
	fin.open("test2.txt");
	Lexer* l = new Lexer();
	Parser* p = new Parser(l, fin);
	//Token* t = l->scan(fin);
	//cout << t->toString() << '\t'<< t->t.printmap[t->tag] << endl;
	p->program(fin);

	

}

//Lexer* l = new Lexer();
//ifstream fin;



/*
TO DO
------
1) write parser
2) test classes



Good to know
---------------




Current issues
----------------------
possibly:
   public Break() {
	  if( Stmt::get_Enclosing() == Stmt::get_Null() ) error("unenclosed break");
	  stmt = Stmt::get_Enclosing();
   }
	based on the way the get functions are set up, this might always happen. Unless
	Null and enclosing are modified later, which they shouldn't be able to since they're
	static variables. Might switch them to just be static members isntead later.



classes to be tested:
----------------------
Break.h //might actually contain issues
Else.h
If.h
Or.h


*/
