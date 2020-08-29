#include "pointerEx.h"

namespace pointerEx {
	void testRef()
	{
		{
			int a = 1, b = 2;
			int& r = a;
			cout << r << " " << &r << endl;
		}
		{
			int x = 9;
			const int& r = x;// r++ 같이 r을 통해서 값 변경은 안됨. 읽기전용으로 만들수 있음)
			cout << r << " " << &r << endl;
		}
	}

	void testPointer()
	{
		int v = 0;
		int* a, ** b, *** c;
		a = &v;
		b = &a;
		c = &b;
		cout << *a << " " << a << " " << &a << endl;
		cout << **b << " " << *b << " " << b << " " << &b << endl;
		cout << ***c << " " << **c << " " << *c << " " << c << " " << &c << endl;
	}

	void testArr2()
	{
		// 이방법 맑고 다른거 잇는데
		int** array = new int* [10]; // allocate an array of 10 int pointers — these are our rows 
		for (int count = 0; count < 10; ++count)
			array[count] = new int[5]; // these are our columns

		array[9][4] = 3; // This is the same as (array[9])[4] = 3;

		for (int count = 0; count < 10; ++count)
			delete[] array[count];

		delete[] array; // this needs to be done last


		// 이게 편한 방법 https://codeng.tistory.com/8
		int height = 8, width = 6;
		int** arr;
		arr = (int**)malloc(sizeof(int*) * height);
		arr[0] = (int*)malloc(sizeof(int) * width * height);
		for (int i = 1; i < height; i++) {
			arr[i] = arr[i - 1] + width;
		}

		free(arr[0]);
		free(arr);
	}

}