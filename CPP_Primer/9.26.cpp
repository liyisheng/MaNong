/*************************************************************************
    > File Name: 9.26.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 03:59:16 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(int argc, char *argv[])
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> ivec(ia, ia + 11);
	list<int> ilist(ia, ia + 11);

	for(vector<int>::iterator it = ivec.begin(); it != ivec.end();)
	{
		if(*it % 2)
			it = ivec.erase(it);
		else
			++it;
	}

	for(int i = 0; i != ivec.size(); ++i)
		cout << ivec[i] << endl;

	for(list<int>::iterator it = ilist.begin(); it != ilist.end();)
	{
		if(*it % 2 == 0 )
			it = ilist.erase(it);
		else
			++it;
	}

	for(list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
		cout << *it << endl;
	
	return 0;
}
