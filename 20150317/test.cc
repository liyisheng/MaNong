/*************************************************************************
    > File Name: test.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 20 Mar 2015 03:15:05 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base
{
	protected:
		Base(int ix = 0) : ix_(ix){
		}
		int fun()
		{
			return ix_;
		}
	private:
		int ix_;
};

class Child : public Base
{
	public:
		Child(int xp) : Base(xp){
		}
		int fun2()
		{
			return fun();
		}
	public:
		Base b;
};

int main(int argc, char *argv[])
{
	return 0;
}
