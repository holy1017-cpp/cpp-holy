#include "functionEx.h"
namespace functionEx {
	void test()
	{
		{
			int i = 5;
			cout << "functionEx.i=" << i << endl;
			fc1(i);
			cout << "functionEx.i=" << i << endl;	
			fc2(i);
			cout << "functionEx.i=" << i << endl;
		}
	}
	void test3()
	{
		ex e;
		e.x = 4;
		e.y = 5;
		fc3(e);
	}

	void test4()
	{
		fc4();
		fc4('g');
		fc4(65);
		fc4('6',87);
	}

	void fc1(int i)
	{
		i = 9;
	}
	void fc2(int& i)
	{
		i = 9;
	}

	void fc3(const ex& e) {
		cout << "functionEx.fc3.x=" << e.x << endl;
		cout << "functionEx.fc3.y=" << e.y << endl;
	}
	void fc4(char c, int i)
	{
		cout << "functionEx.fc4.c=" << c << endl;
		cout << "functionEx.fc4.i=" << i << endl;
	}
}