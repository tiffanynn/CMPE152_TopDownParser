#pragma once
#include <unordered_map>
#include <string>
using namespace std;
class Tag //class is used to access information about tags
{
public:
	const int AND = 256, BREAK = 258, DO = 259, ELSE = 260, EQ = 261, FALSE = 262, GE = 263,
		ID = 264, IF = 265, INDEX = 266, LE = 267, MINUS = 268, NE = 269, NUM = 270, OR = 271, REAL = 272,
		TEMP = 273, TRUE = 274, WHILE = 275, INT = 276, FLOAT = 277, BOOL = 278, MYEOF = 420, ERROR = 999;
	unordered_map<int, string> printmap; //used for printing, access the symbol name by its tag, which is defined above.
	Tag();
};

Tag::Tag()
{
	printmap[256] = "AND";
	printmap[258] = "BEAK";
	printmap[259] = "DO";
	printmap[260] = "ELSE";
	printmap[261] = "EQ";
	printmap[262] = "FALSE";
	printmap[263] = "GE";
	printmap[264] = "ID";
	printmap[265] = "IF";
	printmap[266] = "INDEX";
	printmap[267] = "LE";
	printmap[268] = "MINUS";
	printmap[269] = "NE";
	printmap[270] = "NUM";
	printmap[271] = "OR";
	printmap[272] = "BASE_TYPE";
	printmap[273] = "TEMP";
	printmap[274] = "TRUE";
	printmap[275] = "WHILE";
	printmap[276] = "BASE_TYPE";
	printmap[277] = "FLOAT";
	printmap[278] = "BOOL";
	printmap[420] = "EOF";
	printmap[(int)';'] = ';';
	printmap[(int)'='] = '=';
	printmap[(int)'<'] = '<';
	printmap[(int)'>'] = '>';
	printmap[(int)'('] = '(';
	printmap[(int)')'] = ')';
	printmap[(int)'{'] = '{';
	printmap[(int)'}'] = '}';
	printmap[(int)'+'] = '+';
	printmap[(int)'-'] = '-';
	printmap[(int)'*'] = '*';
	printmap[(int)'/'] = '/';
	printmap[(int)'&'] = "LOGICAL AND";
	printmap[(int)'|'] = "LOGICAL OR";

	printmap[999] = "ERROR";
}