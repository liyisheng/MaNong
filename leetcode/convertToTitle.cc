/*************************************************************************
    > File Name: convertToTitle.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 24 Mar 2015 10:39:21 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

string convertToTitle(int n) {

	int base = 'A' - 1;
	string ret;
	char c;
	while(n)
	{
		c = n % 26;
		if(!c)
		{

			c = 'Z';
			n--;
		}
		else
			c = c + base;
		n = n/26;
		ret.insert(0,1,c);
	}
	return ret;
}
int main(int argc, char *argv[])
{
	cout << convertToTitle(26)<< endl;
	cout << convertToTitle(28)<< endl;
	cout << convertToTitle(702)<< endl;
	cout << convertToTitle(18278)<< endl;
	return 0;
}
