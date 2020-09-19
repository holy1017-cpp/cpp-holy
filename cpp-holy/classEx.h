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

		static int cr;
		static int de;

	public:
		Counter();
		Counter(int v);
		Counter(int v, int i);
		Counter(int v, int i, const char* c);

		// ���� ������. ���� ���� ���ҽ� �������� ���
		// ���� ����� �������ʿ��� �������翡�� ���� �߻�
		Counter(const Counter& o);

		// �̵� ������
		Counter(Counter&& o);

		Counter add(const Counter& o) const;

		void CReset();

		void print();;

		// �������ʿ��� �������翡�� ���� �߻�
		~Counter();
	};

	void test();



}

#endif