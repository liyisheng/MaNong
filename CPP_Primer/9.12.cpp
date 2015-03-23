/*************************************************************************
    > File Name: 9.12.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 09:04:44 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool
fun(vector<int>::iterator beg, vector<int>::iterator end, int ival)
{
	for(; beg != end && *beg != ival; ++beg);
	if(beg != end)
		return true;
	else
		return false;
}

int main(int argc, char *argv[])
{
	return 0;
}
