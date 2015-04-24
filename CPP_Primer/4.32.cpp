/*************************************************************************
    > File Name: 4.32.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 20 Apr 2015 09:16:14 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> ivec(a , a + 8);
	for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
		cout << *it << endl;
	return 0;
}
