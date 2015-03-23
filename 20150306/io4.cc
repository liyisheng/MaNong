/*************************************************************************
    > File Name: io4.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 03:15:43 PM CST
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
	int ival = 512;
	int ival2 = 1024;

	stringstream ss;
	ss << "ival = " << ival << " " << "ival2 = " << ival2 << endl;

	string str = ss.str();
	cout << str << endl;
	
//	string str1;
	while(ss >> str)
	{
		cout << str << endl;
	}
	return 0;
}
