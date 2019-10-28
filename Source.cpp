#include "../lexer/lexer.h"
//#include <vector>
#include "../inter/Stmt.h"
#include "../inter/block.h"
#include "../symbols/type.h"
#include "../inter/expr.h"
#include "Tag.h"
#include "../inter/id.h"
#include "../inter/prog.h"
#include "../inter/logic.h"
#include "../symbols/type.h"
int main()
{
	Tag te;
	Expr* e1 = new Expr();
	Expr *e2 = new Expr();;
	Type* tp = new Type("int", 278, 4);
	Type* tp2 = new Type("float", 278, 8);
	Type* t1 = tp->get_Bool();
	tp2 = tp->get_Bool();
	Token tok(';');
	Token* tge = &tok;
	Logical g(tge, e1, e2);
	if (g.check(t1, tp2) == t1)
	{
		cout << "true" << endl;
	}

	

}


/*
TO DO
------
1) finish creating numeric check for type class
2) finish Expr class
Good to know
---------------
Bool, Char, Int, etc can't be members of 
Current issues
----------------------
Troubling functions
--------------------
Type::Max()
*/










//int main()
//{
//
//	ifstream fin;
//	Lexer lex;
//	fin.open("test.txt");
//	Word* wp;
//	wp = lex.words["int"];
//	while (!fin.fail())
//	{
//		Token* t= lex.scan(fin);
//		if (t->tag == 420) {
//			cout << t->toString() << '\t' << t->t.printmap[t->tag] << endl;
//			break;
//		}
//		if (t->tag == 999) {
//			cout << t->toString() << '\t' << t->t.printmap[t->tag] << endl;
//			break;
//		}
//		cout <<  t->toString()<< '\t'<< t->t.printmap[t->tag]  << endl;
//	}
//	fin.close();
//	//for (auto it = lex.words.begin(); it != lex.words.end(); ++it)
//	//{
//	//	cout << "First: " << it->first << "\tSecond: " << it->second << endl;
//	//}
//
//}
