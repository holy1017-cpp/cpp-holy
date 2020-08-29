#include<stdio.h>
#include "stdioEx.h"

namespace stdioEx {
	int test() {
		char e, b;
		printf("input:");
		scanf_s("%c", &b, 1);
		rewind(stdin);
		printf("input:");
		scanf_s("%c", &e, 1);
		rewind(stdin);
		printf("b: %c , e: %c",b,e);
		printf("\n");
		return 0;
	}
}