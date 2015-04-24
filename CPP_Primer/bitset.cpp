/*************************************************************************
    > File Name: bitset.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 19 Apr 2015 04:55:26 PM CST
 ************************************************************************/

#include<iostream>
#include<bitset>
using namespace std;

int main(int argc, char *argv[])
{
	string s = "1100";
	bitset<8> b(s);
	cout << b << endl;
	cout << b.test(1) << endl;
	return 0;
}

void func(int *p)
{
	*p =+1;
}
