#pragma once
#include <vector>
#include "../lexer/lexer.h"

class Node
{	
public:
	Node();
	int lexline;
	vector<Node> children;
	vector<Node> get_children();
};

Node::Node()
{
 lexline= line; //error here, cannot identify line from the lexer header file

 }

vector<Node> Node::get_children()
{
	return children;
}