/*************************************************************************
    > File Name: x.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 04:24:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class X
{
	private:
		int ival1_;
		int ival2_;
	public:
		X(int ival): ival2_(ival), ival1_(ival2_){}
		void print()
		{
			cout << "ival1 = " << ival1_ << endl;
			cout << "ival2 = " << ival2_ << endl;
		}

};
int main(int argc, char *argv[])
{
	X x1(3);
	x1.print();
	return 0;
}
