/*************************************************************************
    > File Name: 9.13.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 09:08:35 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

vector<int> iterator
fun(vector<int>::iterator beg, vector<int>::iterator end, int ival)
{
	while(beg != end)
		if(*beg == ival)
			break;
		else
			++beg;
	return beg;
}
int main(int argc, char *argv[])
{
	return 0;
}
