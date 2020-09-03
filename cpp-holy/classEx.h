#pragma once

#ifndef classEx_H
#define classEx_H

#include <iostream>

using namespace std;

namespace classEx {

	class Counter {
		int v;
		int i;
		char* c;
	public:
		Counter() :
			v { 30 },
			i {	40 }
		{
			CReset();
			print();
		}

		Counter(int v, int i,const char* c)  {
			this->c = new char[strlen(c)+1];
			strcpy_s(this->c, strlen(c) + 1, c);
			print();
		}

		Counter(int v) : i{ 60 } {
			this->v = v;			
			CReset();
			print();
		}

		Counter(int v, int i) {
			this->v=v ;
			this->i=i ;
			CReset();
			print();
		}

		void CReset() {
			this->c = new char[1];
			this->c[0] = 0;
		}

		void print() {
			cout << v << ",";
			cout << i << ",";
			cout << c << endl;
		};

		~Counter()
		{
			delete[] c;
			print();
		}
	};

	void test();



}

#endif