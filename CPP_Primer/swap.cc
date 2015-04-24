/*************************************************************************
    > File Name: swap.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 23 Apr 2015 02:04:02 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v1(a, a + 5);
	vector<int> v2(a + 4, a + 10);

	vector<int>::iterator it1 = v1.begin();
	vector<int>::iterator it2 = v2.begin();
	cout << *it1 << " "<< *it2 << endl;
	cout << v1[0] << " " << v2[0] << endl;
	v1.swap(v2);

	cout << *it1 << " "<< *it2 << endl;
	cout << v1[0] << " " << v2[0] << endl;
	cout << v1[0] << " " << v2[0] << endl;


	return 0;
}
