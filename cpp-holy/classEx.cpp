#include "classEx.h"

namespace classEx {
	
	int Counter::cr = 0;
	int Counter::de = 0;

	void test()
	{
		Counter c1;
		Counter c2(5);
		Counter c3(3, 4); // 461d6c04-e746-4895-b288-2041e5212ab3

		Counter arr[3] = { Counter(9),Counter(8),Counter(7) };

		Counter c4 = c3; // 461d6c04-e746-4895-b288-2041e5212ab3

		Counter c5(c4); // 461d6c04-e746-4895-b288-2041e5212ab3
		Counter c6(c3.add(c3)); // 461d6c04-e746-4895-b288-2041e5212ab3

		//c5.print();
		cout << "test END" << endl;
	}

	/* *** 생성자 *** */

	inline Counter::Counter() :
		v{ 30 },
		i{ 40 }
	{		
		CReset();
		++cr;
		print();
	}

	inline Counter::Counter(int v) :
		v{ v },
		i{ 60 }
	{
		//this->v = v;
		CReset();
		++cr;
		print();
	}

	inline Counter::Counter(int v, int i) :
		v{ v },
		i{ i }
	{
		//this->v=v ;
		//this->i=i ;
		CReset();
		++cr;
		print();
	}

	inline Counter::Counter(int v, int i, const char* c) {

		this->c = new char[strlen(c) + 1];
		strcpy_s(this->c, strlen(c) + 1, c);

		++cr;
		print();
	}

	// 복사 생성자. 직접 생성 안할시 얕은복사 사용
	// 얕은 복사는 포인터쪽에서 문제 발생
	inline Counter::Counter(const Counter& o) :
		v{ o.v },
		i{ o.i },
		c{ o.c }
	{
		//cout << "copy" << endl;
		//v = o.v;
		//i = o.i;
		//c = o.c;

		this->c = new char[strlen(o.c) + 1];
		strcpy_s(this->c, strlen(o.c) + 1, o.c);

		++cr;
		print();
	}

	// 이동 생성자
	inline Counter::Counter(Counter&& o) :
		v{ o.v },
		i{ o.i },
		c{ o.c }
	{
		//cout << "move" << endl;
		//cout << &o.c << ", ";
		//cout << o.c << endl;
		//cout << &c << ", ";
		//cout << c << endl;
		o.c = nullptr; //기존것이 소멸하면서 없애버리는걸 막기 위함
		++cr;
		print();
	}

	/* *** 생성자 끝 *** */

	inline Counter Counter::add(const Counter& o) const {
		Counter t;
		t.v = v + o.v;
		t.i = i + o.i;
		return t;// 반환 후 이동 생성자에서 처리된후 소멸자 작동
	}

	inline void Counter::CReset() {
		this->c = new char[1];
		this->c[0] = 0;
	}

	inline void Counter::print() {
		id.print();
		cout << cr << " : " ;
		cout << v << ", ";
		cout << i << ", ";
		cout << &c << ", ";
		cout << c << endl; // 이동 생성자 사용후 소멸자 작동시 NULL 오류나서 개선 필요
	}

	// 포인터쪽에서 얕은복사에서 문제 발생

	inline Counter::~Counter()
	{
		delete[] c;
		id.print();
		++de;
		cout << "delete : " <<de<< endl;
		//print(); // 이동 생성자 사용시 오류나서 개선 필요
	}
}