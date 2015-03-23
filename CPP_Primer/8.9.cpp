/*************************************************************************
    > File Name: 8.9.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 01:23:22 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<fstream>
#include<ios>
using namespace std;

int main(int argc, char *argv[])
{
	//ofstream os("1.text", ios_base::app);
	ifstream in("1.txt");
	string s;
	vector<string> svec;
	while(getline(in, s))
	{
		svec.push_back(s);
	}

	for(int i = 0 ; i != svec.size(); ++i)
		cout << svec[i] << endl;

	ifstream in1("1.txt");

	vector<string> svec1;

	while(in1 >> s)
	{
		svec1.push_back(s);
	}

	for(int i = 0 ; i != svec1.size(); ++i)
		cout << svec1[i] << endl;

	return 0;
}
