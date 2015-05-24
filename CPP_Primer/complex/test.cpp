/*************************************************************************
    > File Name: test.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 02 May 2015 11:03:12 PM CST
 ************************************************************************/

#include<iostream>
#include"complex.h"
using namespace std;

int main(int argc, char *argv[])
{
	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);
	
	cout << c1 << endl;
	cout << c2 << endl;
	cout << c1 - c2 << endl;
	cout << c1 + c2 << endl;
	return 0;
}
