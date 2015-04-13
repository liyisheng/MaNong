/*************************************************************************
    > File Name: test.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 10 Apr 2015 05:17:12 AM PDT
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main(int argc, char *argv[])
{
	int a;
	cout << sizeof(int) << endl;
	memset((char *)&a + 2, 2, 2);
	cout << a;
	return 0;
}
