/*************************************************************************
    > File Name: 11.21.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 04:47:11 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

int main(int argc, char *argv[])
{
	int ia[] = {1, 2, 3, 0, 4, 5, 6, 7, 0,8};
	list<int> ilist(ia, ia + 10);
	list<int>::reverse_iterator riter;

	riter = find(ilist.rbegin(), ilist.rend(), 0);
	return 0;
}
