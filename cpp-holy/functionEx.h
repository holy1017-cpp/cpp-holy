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
	void testswap();
	void fc1(int);
	void fc2(int&);
	void fc3(const ex &);
	void fc4(char c = 'y', int i = 8);
	void swap(int&, int&);

	const int cmax = 9;
	struct St {
		int a, b;
		char c[cmax]; // 실제론 4바이트 단위로 처리됨
		int d;
	};

	void stcp(char* o, const char* a,int m= cmax);

	void StPrint(St& st);
	
	void StAdd(St& ori, St& add);
	void StAdd(St& ori, int add);
	
	void StSet(St& s, int a, int b, const char* c, int d);
	St StSet(int a, int b, const char* c, int d);

	void testStcut();
	void testStPrint();
	void testStPrint2();
	void testStPrint3();

	const char* stcut(std::string& t);


	void testStPrint4();
}

#endif