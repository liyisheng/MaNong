/*************************************************************************
    > File Name: 11.15.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 02:15:29 PM CST
 ************************************************************************/

#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int ia[] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 100, 100};
	list<int> ilist(ia, ia + 13);

	for(list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
		cout << *it << endl;


//	sort(ilist.begin(), ilist.end());
	
	ilist.sort();
	vector<int> ivec;
	unique_copy(ilist.begin(), ilist.end(), back_inserter(ivec));

	for(vector<int>::size_type i = 0; i != ivec.size(); ++i)
		cout << ivec[i] << "  ";
	cout << endl;
	return 0;
}
