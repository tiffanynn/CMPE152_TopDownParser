#include "Lexer.h"
#include "Or.h"
#include "Break.h"
#include "Parser.h"
#include <string>
using namespace std;
string getIndentString(int indent)
{
	stringstream sb;
	for (int i = 0; i < indent; i++)
	{
		sb << "|\t";
	}
	return sb.str();

}

void printTree(Node* root, int indent, stringstream& s)
{
	s << getIndentString(indent);
	s << "+--";
	s << root->getNodeStr();
	s << "\n";
	for (Node* n : root->getChildren())
	{
		printTree(n, indent + 1, s);
	}

}
string printTree(Node* node)
{
	int indent = 0;
	stringstream sb;
	printTree(node, indent, sb);
	return sb.str();
}




int main()
{

	
	ifstream fin;
	fin.open("test2.txt");
	Lexer* l = new Lexer();
	Parser* p = new Parser(l, fin);
	Prog* tree = p->program(fin);
	cout << "\nSyntax Tree\n";
	string treestr = printTree(tree);
	cout << treestr << endl;
	

}


