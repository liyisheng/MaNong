/*************************************************************************
  > File Name: test.cc
  > Author: liyisheng
  > Mail: liyishengchn@gmail.com 
  > Created Time: Mon 20 Apr 2015 02:05:48 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
class A
{

	public:
		void f()
		{

			printf("A\n");
		}
};

class B: public A
{

	public:
		virtual void f()
		{

			printf("B\n");
		}
};

int main()
{

	A *a = new B;
	a->f();
	delete a;
	return 0;
}
