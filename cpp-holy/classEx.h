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

		// 복사 생성자. 직접 생성 안할시 얕은복사 사용
		// 얕은 복사는 포인터쪽에서 얕은복사에서 문제 발생
		Counter(const Counter& o);

		// 이동 생성자
		Counter(Counter&& o);

		Counter add(const Counter& o) const;

		void CReset();

		void print();;

		// 포인터쪽에서 얕은복사에서 문제 발생
		~Counter();
	};

	void test();



}

#endif