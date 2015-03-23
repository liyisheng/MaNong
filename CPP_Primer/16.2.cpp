/*************************************************************************
    > File Name: 16.2.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 21 Mar 2015 10:30:44 PM CST
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;


template <class T>
ostream& fun(ostream &out, const T &v)
{
	out << v << endl;
	return out;
}

ostream& fun1(ostream &out, const int& v)
{
	cout << v << endl;
}
int main(int argc, char *argv[])
{
	fun(cout, 123124);
	//fun1(cout, 1231);
	fun(cout, "abcdefghijklmnopqrstuvwxyz");
	ofstream out("16.2.txt");
	fun(out, 12123124);
	ostringstream sout;
	fun(sout, "1ouaff");
	cout << sout.str() << endl;
	return 0;
}
