/*************************************************************************
    > File Name: 9.24.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 12:04:01 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> ivec;
	int ival;
	while(cin >> ival)
		ivec.push_back(ival);

	cout << """" << ivec[0] << endl;
	cout << """""" << ivec.front() << endl;
	cout << """" << *ivec.begin() << endl; 

//	ivec.front() = 2;
//	ivec[0] = 2;
	*ivec.begin() = 2;
	cout << ivec[0] << endl;
	return 0;
}
