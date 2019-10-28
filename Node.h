#pragma once
#include <vector>
class Node //important class
{
public:
	int line;
	Node();
	vector<Node*> children;
	vector<Node*> getChildren();
	virtual string getNodeStr();
	void error(string);
};
Node::Node()
{
	line = 0;
}

void Node::error(string s)
{
	cout << "Error: " << s << endl;
}

vector<Node*> Node::getChildren()
{
	return children;
}

string Node::getNodeStr()
{
	return ""; //This shouldn't happen.
}