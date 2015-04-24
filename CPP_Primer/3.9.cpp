/*************************************************************************
    > File Name: 3.9.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 19 Apr 2015 04:10:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string result_str, str;
	while(cin >> str)
	{
		result_str = result_str + str;
	}

	cout << result_str << endl;

	return 0;
}
