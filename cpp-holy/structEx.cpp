#include "structEx.h"

double structRx::xy(Ex e)
{
	return e.x*e.y;
}

void structRx::test()
{
	Ex e;
	e.x = 3;
	e.y = 4;
	cout << "structRx::test:"<<xy(e) << endl;
	
}
