/*************************************************************************
    > File Name: trav_string.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 10:39:17 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(int argc, char *argv[])
{
	string a;
	cin >> a;
	string::iterator it = a.begin();

	for(; it != a.end(); it++)
	{
		*it = toupper(*it);
	}

	cout << a << endl;
	return 0;

}
