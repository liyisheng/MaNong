/*************************************************************************
    > File Name: 9.36.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 05:36:45 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
	string str = "abcdefg";
	vector<char> cvec(str.begin(), str.end());

	string str2(cvec.begin(), cvec.end());

	cout << str2 <<endl;

	return 0;
}
