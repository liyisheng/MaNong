/*************************************************************************
    > File Name: 3.7.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 13 Mar 2015 04:02:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string s1, s2;
	cin >> s1 >> s2;
	if(s1 == s2)
	{
		cout << "==" << endl;
	}else if(s1 > s2)
	{
		cout << s1 << endl;
	}else
	{
		cout << s2 << endl;
	}
	return 0;
}
