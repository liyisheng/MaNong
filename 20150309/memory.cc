/*************************************************************************
    > File Name: memory.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 09 Mar 2015 11:30:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int a = 0; //全局初始化区

char *p1; //全局未初始化区

int main(int argc, char *argv[])
{
	int b; //栈
	char s[] = "abc";
	char *p2;
	char *p3 =  "123456";
	static int c = 0; //全局静态区
	p1 = (char *)malloc(10);
	p2 = (char *)malloc(20);
	strcpy(p1, "123456");

	return 0;
}
