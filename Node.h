#pragma once
#include "lexer.h"

class Node
{	
public:
	Node();
	vector<Node> children;
	vector<Node> get_children();
};

Node::Node()
{

 }

vector<Node> Node::get_children()
{
	return children;
}
