/*************************************************************************
    > File Name: null.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 08:46:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class NullClass
{

};

int main(int argc, char *argv[])
{
	NullClass obj1;
	NullClass obj2;
	cout << "&obj1 " << &obj1 << endl;
	cout << "&obj2 " << &obj2 << endl;
	cout << sizeof(NullClass) << endl;

	return 0;
}
