/*************************************************************************
    > File Name: 11.22.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 04:56:31 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

int main(int argc, char *argv[])
{
	int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> ivec(ia, ia + 10);

	list<int> ilist;
	vector<int>::reverse_iterator rstart, rend;

	rstart = ivec.rbegin() + 3;
//	for(int cnt1 = 1; cnt1 != 4; ++cnt1)
//		++rstart;
	rend = ivec.rend() - 2;
//	for(int cnt2 = 1; cnt2 != 6; ++cnt2)
//		++rend;

//	copy(rstart, rend, inserter(ilist, ilist.begin()));
	copy(rstart, rend, inserter(ilist,ilist.begin()));

	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
		cout << *iter << endl;
	return 0;
}
