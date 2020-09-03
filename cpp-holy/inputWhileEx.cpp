
#include <thread>
#include <Windows.h>

#include "inputWhileEx.h"

namespace inputWhileEx {

	int a[3] = {0,1,2}, * b = &a[0], ** c = &b, & ar = a[0];
	int r=0;
	bool w = true;

	void test()
	{
		thread t1(pointChg);
		while (w)
		{
			printf_s("%d %d %d %d %d \n",a[0],a[1],a[2],*b,**c);
			printf_s("%p %p %p \n",&a[0],&a[1],&a[2]);
			printf_s("%p %p \n",&b,&c);
			printf_s("%p %p \n",b,c);
			printf_s("\n");
			Sleep(1000);
		}
	}

	void pointChg() {
		while (w)
		{
			if (r>=2)
			{
				r = 0;
			}
			else
			{
				r++;
			}
			b = &a[r];
			Sleep(1000);
		}
	}
}