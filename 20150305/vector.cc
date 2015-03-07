/*************************************************************************
    > File Name: vector.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Mar 2015 11:50:53 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{

	vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	cout << vec.size() << endl;

	for(int idx = 0; idx != vec.size(); idx++)
	{
		cout << vec[idx] << endl;
	}

	vector<int> vec2(vec);
	vector<int>::iterator it2 = vec2.begin();
	for(; it2 != vec2.end(); it2++)
	{
		cout<< *it2 << endl;
	}

	vector<int> vec3(vec.begin(), vec.end());
	vector<int>::iterator it3 = vec3.begin();
	for(; it3 != vec3.end(); it3++)
		cout << *it3 << endl;


	return 0;
}
