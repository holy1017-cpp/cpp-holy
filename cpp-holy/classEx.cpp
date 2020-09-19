#include "classEx.h"

void classEx::test()
{
	//Counter c1;
	//Counter c2(5);
	Counter c3(3,4);

	//Counter arr[3] = { Counter(9),Counter(8),Counter(7) };

	Counter c4=c3;

	Counter c5(c4.add(c3));

	//c5.print();
}
