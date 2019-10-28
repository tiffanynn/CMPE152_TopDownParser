#include "Or.h"

int main()
{
	Token* t = Word::get_True(); // this returns the pseudo 'resereved' word "true" into t
	Type* typ = Type::get_Bool(); //returns pseudo 'reserved' type "bool" and places it into typ
	Expr* e1 = new Expr(t, typ);
	Expr* e2 = new Expr(t, typ); //just made an exact copy for convenience
	Or* orpointer = new Or(t, e1, e2); //should have successfully created an Or object.

	//now test the functions, but there's just one in this case.

	cout << orpointer->getNodeStr() << endl;
	//can also test that the member of the objects are what they're supposed to be

	cout << orpointer->tok->toString() << endl; // <-- should print "true"

}