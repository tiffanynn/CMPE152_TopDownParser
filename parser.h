#include "lexer.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "token.h"
using namespace std;

class Parser{

};

//hard-code the logic for the basic language
/*

For our reference:
---------------------
program -> block
block -> { decls stmts }
decls -> ε | decls decl
decl -> type id ;
type -> int | float | bool
stmts -> ε | stmts stmt
assign -> id = allexpr ;
stmt -> assign | if (allexpr) stmt | if (allexpr) stmt else stmt | while (allexpr) stmt
 | do stmt while (allexpr) ; | for (assign allexpr ; incdecexpr) stmt | break ; | block
allexpr -> allexpr || andexpr | andexpr
andexpr -> andexpr && equal | equal
equal -> equal == rel | equal != rel | rel
rel -> expr < expr | expr <= expr | expr > expr | expr >= expr | expr
expr -> expr + term | expr – term | term
term -> term * factor | term / factor | factor
incdecexpr -> id++ | id--
factor -> (allexpr) | incdecexpr | id | num | real | true | false

*/