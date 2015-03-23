/*************************************************************************
    > File Name: 9.18.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 11:24:03 AM CST
 ************************************************************************/

#include<iostream>
#include<list>
#include<deque>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
	list<int> ilist;
	for(int i = 0; i != 20; ++i)
		ilist.push_back(i);

	deque<int> de1;	
	deque<int> de2;
	list<int>::iterator it = ilist.begin();
	for(; it != ilist.end(); ++it)
	{
		if(*it % 2 == 0)
			de1.insert(de1.end(), *it);
		else
			de2.insert(de2.end(), *it);
	}


	for(int i = 0; i != de1.size(); ++i)
		cout << de1[i] << " ";
	cout << endl;
	for(int i = 0; i != de2.size(); ++i)
		cout << de2[i] << " ";
	return 0;
}
