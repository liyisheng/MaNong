/*************************************************************************
    > File Name: 17.25.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 22 Mar 2015 05:27:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class A
{
		
};
class B : public A
{

};

class C : protected B
{

};

class X
{

};

class D : public X, public C
{
	
};
int main(int argc, char *argv[])
{
	D *pd = new D;
	B *pb = pd;
	C  *pc = new C;
//	B *pb = pc;
	return 0;
}
