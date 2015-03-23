/*************************************************************************
    > File Name: nullpointcall.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 09 Mar 2015 11:35:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class CNullPointCall
{
	public:
		static void test1();
		void test2();
		void test3(int ival);
		void test4();
	private:
		static int iStatic_;
		int ival_;
};
int CNullPointCall::iStatic_ = 0;

void CNullPointCall::test1()
{
	cout << "test1() : iStatic_ = "<< iStatic_ << endl;
}

void CNullPointCall::test2()
{
	cout << "test2()" << endl;
}

void CNullPointCall::test3(int ival)
{
	cout<< "test3(): ival = " << ival<< endl;
}

void CNullPointCall::test4()
{
	cout << "test4() : ival_ = " << this->ival_ <<endl;
}

//void CNullPointCall::test1(CNullPointCall *const this)
//{
//	this = NULL;
//}


int main(int argc, char *argv[])
{
	CNullPointCall *q;
	CNullPointCall *p = NULL;
	p->test1();
	p->test2();
	p->test3(4);
	p->test4();

	return 0;
}
