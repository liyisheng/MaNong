/*************************************************************************
    > File Name: 3.8.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 13 Mar 2015 04:06:10 PM CST
 ************************************************************************/

#include<iostream>
#include<list>
#include<string>
#include<iterator>
using namespace std;


int main(int argc, char *argv[])
{
	string s;
	string t;

	cin >> s; 
	while(getline(cin, t))
	{
		s = s + ' ' + t;
	}
	cout << s << endl;


	return 0;
}

