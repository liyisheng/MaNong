/*************************************************************************
    > File Name: union.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 20 Apr 2015 01:54:48 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
union X{
		int x;
		char y[4];
};	
int main(int argc, char *argv[])
{
	X a;
	a.x = 0x11223344;
	printf("%x\n", a.y[3]);


	return 0;
}
