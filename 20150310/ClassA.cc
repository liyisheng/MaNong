/*************************************************************************
    > File Name: ClassA.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 10 Mar 2015 11:03:32 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A
{
	public:
		A(int n = 0)
		{
			value = n;
		}
		A(A &other)
		{
			value = other.value;
		}
		
		void print()
		{
			cout << value << endl;
		}
	private:
		int value;
};

int main(int argc, char *argv[])
{
	A a(10);
	A &aa = a;
	A b = aa;
	b.print();
	return 0;
}
