/*************************************************************************
    > File Name: test.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 11:51:36 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

const string &manip(const string &s)
{
	return s;
}

int main(int argc, char *argv[])
{
	cout << manip("abcdef") << endl;

	string s1("badjfoa");
	const string &a =  manip(s1);
	cout << a << endl;

	const string &a1 = manip("afjoa");
	cout << a1 << endl;
	cout << (a == s1) << endl;
	const string &b = "bcd3";
	const string &c = b;
	cout << b << endl;
	cout << c;
	return 0;
}
