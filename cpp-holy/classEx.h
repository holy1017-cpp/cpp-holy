#pragma once

#ifndef classEx_H
#define classEx_H

#include <iostream>
#include "guidEx.h"

using namespace std;

namespace classEx {

	class Counter {
		int v;
		int i;

		char* c;

		guidEx::CGUID id;

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

		// ���� ������. ���� ���� ���ҽ� �������� ���
		// ���� ����� �������ʿ��� �������翡�� ���� �߻�
		Counter(const Counter& o) {
			v = o.v;
			i = o.i;
			c = o.c;

			this->c = new char[strlen(o.c) + 1];
			strcpy_s(this->c, strlen(o.c) + 1, o.c);

			print();
		}

		Counter add(const Counter& o) const {
			Counter t;
			t.v = v + o.v;
			t.i = i + o.i;
			return t;
		}

		void CReset() {
			this->c = new char[1];
			this->c[0] = 0;
		}

		void print() {
			id.print();
			cout << v << ", ";
			cout << i << ", ";
			cout << c << endl;
		};

		// �������ʿ��� �������翡�� ���� �߻�
		~Counter()
		{
			delete[] c;
			print();
		}
	};

	void test();



}

#endif