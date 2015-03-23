/*************************************************************************
    > File Name: 3.16.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 14 Mar 2015 11:34:43 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
//	vector<int> ivec(10, 42);
	/*
	vector<int> ivec(10);
	for(int i = 0; i != ivec.size(); ++i)	
	{
		ivec[i] = 42;
	}
	*/
	vector<int> ivec;
	for(int i = 0; i != 10; ++i)
		ivec.push_back(42);
	
	for(int i = 0; i != ivec.size(); ++i)
	{
		cout << ivec[i] << endl;
	}
	return 0;
}
