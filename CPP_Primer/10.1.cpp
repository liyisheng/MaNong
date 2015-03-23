/*************************************************************************
    > File Name: 10.1.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 11:40:50 PM CST
 ************************************************************************/

#include<iostream>
#include<utility>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
	pair<string, int> p;
	vector<pair<string,int> > pvec;
	string str;
	int n;
	while(cin >> str >> n)
	{
		pvec.push_back(make_pair(str, n));
	}
	return 0;
}
