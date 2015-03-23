/*************************************************************************
    > File Name: 16.1.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 21 Mar 2015 10:25:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


template <class T>
T abs(const T &v)
{
	if( v < 0)
		return -v;
	else
		return v;
}
int main(int argc, char *argv[])
{
	cout << abs(168) << endl;
	cout << abs(-178.88) << endl;
//	cout << abs("safou");
	return 0;
}
