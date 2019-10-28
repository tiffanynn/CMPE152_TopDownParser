#include "parser.h"
using namespace std;

int main()
{
	Lexer lex;
    Parser p(lex);
	// lex.getNextToken();
    // lex.print();
    
    cout << "Parse tree:" << endl;

    return 0;
}