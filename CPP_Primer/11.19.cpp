/*************************************************************************
    > File Name: 11.19.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 04:39:51 PM CST
 ************************************************************************/

#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
	int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> ivec(ia, ia + 10);
//	for(vector<int>::reverse_iterator it = ivec.rbegin(); it != ivec.rend(); ++it)
//		cout << *it << endl;
	for(vector<int>::iterator it = --ivec.end(); it != --(ivec.begin()); it--)
		cout << *it << endl;
	return 0;
}
