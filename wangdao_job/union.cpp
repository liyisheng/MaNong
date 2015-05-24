/*************************************************************************
    > File Name: union.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 04 May 2015 10:45:43 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;


union student
{
	int i;
	unsigned char ch[2];
};


int main(int argc, char *argv[])
{
	student s;
	s.i = 0x1420;

	printf("%d %d", s.ch[0], s.ch[1]);
	return 0;
}
