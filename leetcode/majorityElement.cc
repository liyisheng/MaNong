/*************************************************************************
    > File Name: majorityElement.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 24 Mar 2015 09:44:58 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int majorityElement(vector<int> &num) {

	map<int, int> count;
	for(int i = 0; i != num.size(); ++i)
	{

		++count[num[i]];
	}
	map<int,int>::const_iterator map_it = count.begin();
	for(; map_it != count.end(); ++map_it)
	{

		if(map_it ->second >= num.size()/2)
			return map_it ->first;
	}
}
int main(int argc, char *argv[])
{
	vector<int> ivec
	return 0;
}


