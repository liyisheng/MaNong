/*************************************************************************
    > File Name: titleToNumber.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 23 Mar 2015 05:51:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int titleToNumber(string s) {

	int base = 'A' - 1;
	int ans = 0;
	for(int i = 0; i != s.length(); ++i)
	{

		ans = ans * 26 + s[i] -base;
	}
	return ans;
}
int main(int argc, char *argv[])
{
	cout << titleToNumber("ZZZ");
	return 0;
}
