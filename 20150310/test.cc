#include<iostream>
#include<stdlib.h>
#include<stdio.h>

class A 
{
	int a;
	static int b;
};

class B
{
	int a;
	char b; };

class C
{
	float a;
	char b;
};

class D
{
	float a;
	int b;
	char c;
};

class E
{
	double a;
	float b;
	int c;
	char d;
};

int main()
{
	printf("%d\n", sizeof(A));
	printf("%d\n", sizeof(B));
	printf("%d\n", sizeof(C));
	printf("%d\n", sizeof(D));
	printf("%d\n", sizeof(E));

	return 0;
}
