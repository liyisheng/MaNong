/*************************************************************************
    > File Name: bubble_vector.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 11:00:44 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{

	vector<int> vec;
	srand(time(NULL));
	for(int i = 0; i < 10; i ++)
	{
		vec.push_back(rand()%100);
	}

	vector<int>::iterator it = vec.begin();
	for(int i = 0; it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	for(int i = 1; i < vec.size(); i++)
	{
		int swap;
		for(int j = 0; j < vec.size() - i; j++)	
		{
			if(vec[j] > vec[j+1])
			{
				swap = vec[j + 1];	
				vec[j+1] = vec[j];
				vec[j] = swap;
			}	
		}
	}


	it = vec.begin();
	for(; it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;
}
