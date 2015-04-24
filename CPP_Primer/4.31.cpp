/*************************************************************************
    > File Name: 4.31.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 20 Apr 2015 09:14:36 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char *argv[])
{
	string str;
	cin >> str;
	
	char *s = new char[str.size() + 1];
	strcpy(s, str.c_str());
	cout << s << endl;
	return 0;
}
