#pragma once
#include <vector>
using namespace std;
class Node //important class
{
public:
	int line;
	Node();
	vector<Node*> children;
	vector<Node*> getChildren();
	virtual string getNodeStr();

};
Node::Node()
{
	line = 0;
}


vector<Node*> Node::getChildren()
{
	return children;
}

string Node::getNodeStr()
{
	return ""; //This shouldn't happen.
}