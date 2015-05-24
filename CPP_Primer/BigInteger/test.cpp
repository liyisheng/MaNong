/*************************************************************************
    > File Name: test.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 04 May 2015 12:14:00 PM CST
 ************************************************************************/

#include<iostream>
#include"BigInteger.h"
using namespace std;

int main(int argc, char *argv[])
{

	BigInteger b1("123456");
	BigInteger b2("654321");

	cout << b1 << endl;
	cout << b2 << endl;
	cout << b1 + b2;
	return 0;
}
