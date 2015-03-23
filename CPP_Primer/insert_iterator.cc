/*************************************************************************
    > File Name: insert_iterator.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 10:38:59 AM CST
 ************************************************************************/

#include<iostream>
#include<list>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	list<int> ilist, ilist2, ilist3;

	for(list<int>::value_type i = 0; i != 4; ++i)
		ilist.push_front(i);
	copy(ilist.begin(), ilist.end(), front_inserter(ilist2));
	copy(ilist.begin(), ilist.end(), inserter(ilist3, ilist3.begin()));

	for(list<int>::iterator it = ilist3.begin(); it != ilist3.end(); ++it)
		cout << *it << endl;
	return 0;
}
