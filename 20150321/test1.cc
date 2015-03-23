/*************************************************************************
    > File Name: test1.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 21 Mar 2015 09:02:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A
{
	public:
		~A()
		{
			cout << "A";
		}
};

class B
{
	public:
		~B()
		{
			cout << "B";
		}
};

class C : public A
{
	public:
		~C()
		{
			cout << "C";
		}
	private:
		B b;
		

};

int main(int argc, char *argv[])
{

	C *pc = new C;
	delete pc;
	return 0;
}
