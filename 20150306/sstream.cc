/*************************************************************************
    > File Name: sstream.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 03:21:34 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		return -1;
	}

	vector<string> vec_str;
	string line;

	while(ifs >> line)
	{
		vec_str.push_back(line);
	}

	stringstream ss;

	vector<string>::iterator sit = vec_str.begin();
	for(; sit != vec_str.end(); ++sit)
	{
		ss << *sit << endl;
	}

	string str;
	while(ss >> str)
	{
		cout << str << endl;
	}
	return 0;
}
