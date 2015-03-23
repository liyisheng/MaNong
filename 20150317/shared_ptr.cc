/*************************************************************************
    > File Name: shared_ptr.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 07:52:52 PM CST
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;

//循环引用－－无法释放对象，造成内存泄露

class Parent;
class Child;

typedef shared_ptr<Parent> parent_ptr;
typedef shared_ptr<Child> child_ptr;

class Child
{
	public:
		Child()
		{
			cout << "Child..." << endl;
		}
		~Child()
		{
			cout << "~Child..." << endl;
		}
		parent_ptr parent_;
};

class Parent
{
	public:
		Parent()
		{
			cout << "Parent..." << endl;
		}
		~Parent()
		{
			cout << "~Parent..." << endl;
		}
//		child_ptr child_;
	weak_ptr<Child> child_; // 通过弱引用来解决shared_ptr的循环引用问题
};
int main(int argc, char *argv[])
{
	parent_ptr parent(new Parent);
	child_ptr child(new Child);

	parent->child_ = child;
	child->parent_ = parent;

	return 0;
}

