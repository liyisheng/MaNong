/*************************************************************************
    > File Name: reference.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Mar 2015 11:30:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int test0(void)
{
	int ival = 10;
	int &refval = ival;

	int ival2 = 20;
	refval = ival2;

	std::cout << "refval = " << refval << std::endl;
	std::cout << "ival = " << ival << std::endl;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int test1(void)
{
	int ival1 = 3;
	int ival2 = 4;
	swap(ival1, ival2);
	cout << "ival1 = " << ival1 << endl;
	cout << "ival1 = " << ival2 << endl;

	return 0;
}

int a[] = { 0, 1, 2, 3, 4};

int & fun(int idx)
{
	return a[idx];
}

int &fun2(int a, int b)
{
	int isum = 0;
	isum = a + b;
	return isum;
}
int main(int argc, char *argv[])
{
	fun(3) = 100;
	cout << a[3] <<endl;
	cout << fun2(3,4) << endl;
	return 0;
}
