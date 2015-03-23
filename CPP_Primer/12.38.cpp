/*************************************************************************
    > File Name: 12.38.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 09:09:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class Foo
{
	public:
		Foo(int x):value(x){}
		int get()
		{
			return value;
		}
	private:	
		int value;
};
class Bar
{
	public:
		Foo Fooval()
		{
			callsFooval++;
			return fval;
		}
	private:
		static int callsFooval;
		static int ival;
		static Foo fval;
};
int Bar::ival = 20;
Foo Bar::fval = Foo(0);
int main(int argc, char *argv[])
{
	return 0;
}
