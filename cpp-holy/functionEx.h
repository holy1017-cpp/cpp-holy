#pragma once

#ifndef functionEx_H
#define functionEx_H

#include <iostream>

using namespace std;

namespace functionEx {

	struct ex
	{
		int x, y;
	};

	void test();
	void test3();
	void test4();
	void fc1(int);
	void fc2(int&);
	void fc3(const ex &);
	void fc4(char c = 'y', int i = 8);

}

#endif