/*************************************************************************
    > File Name: virtual.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 20 Mar 2015 09:43:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class base
{
	public:
		virtual void disp()
		{
			cout << "hello, base" << endl;
		}
		void call_base_1()
		{
			this ->disp();
		}
		void call_base_2()
		{
			base::disp();
		}
};
class child : public base
{
	public:
		void disp()
		{
			cout << " hello, child" << endl;
		}
		void call_child_1()
		{
			disp(); // == this.disp()
		}
		void call_base_2()
		{
			base::disp();
		}

};


int main(int argc, char *argv[])
{

	base obj_base;
	child obj_child;
	obj_base.call_base_1();
	obj_child.call_child_1();
	cout << endl;

	base *pbase = &obj_base;
	pbase->call_base_1();
	pbase->call_base_2();
	cout << endl;

//	pbase = &obj_child;
//	pbase->call_base_1();
//	pbase->call_base_2();


	child *pchild = (child*)pbase;	
	pchild ->call_child_1();
	cout << endl;
	return 0;
}
