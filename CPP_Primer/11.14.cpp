/*************************************************************************
    > File Name: 11.14.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 02:00:42 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> ivec(10);	
	for(int i = 0; i != 10; ++i)
	{
		if(i < 5)
			ivec[i]	= i; 
		else
			ivec[i] = 8;
	}
	
	list<int> ilist;
//	replace_copy(ivec.begin(), ivec.end(), back_inserter(ilist), 8, 9);
//	replace_copy(ivec.begin(), ivec.end(), front_inserter(ilist), 8, 9);
	replace_copy(ivec.begin(), ivec.end(), inserter(ilist, ilist.begin()), 8, 9);

	for(list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
		cout << *it << endl;
	
	return 0;
}
