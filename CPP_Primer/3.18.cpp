/*************************************************************************
    > File Name: 3.18.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 22 Mar 2015 03:29:43 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> ivec(a, a + 10);

	vector<int>::iterator ite = ivec.begin();
	while(ite != ivec.end())
	{
		*ite *= 2;
		ite++;
	}

	vector<int>::const_iterator cite = ivec.cbegin();
	while(cite != ivec.cend())
	{
		cout << *cite << endl;
		cite ++;
	}
	return 0;
}
