#include <stdio.h>

extern int a;

void fun2(void)
{
	printf("here fun2\n");
	a += 2;
	printf("a %d\n", a);
}