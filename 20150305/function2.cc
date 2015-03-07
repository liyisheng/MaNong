/*************************************************************************
    > File Name: function2.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Mar 2015 10:59:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int add(int a, int b = 3)
{
	return a + b;
}

int add(int a, int b, int c)
{
	return a + b + c;
}
int main(int argc, char *argv[])
{
	cout << add(1) << endl;
	cout << add(2, 4) << endl;
	cout << add(1, 2, 3) << endl;
	return 0;
}
