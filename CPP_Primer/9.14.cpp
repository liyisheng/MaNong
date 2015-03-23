/*************************************************************************
    > File Name: 9.14.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 09:10:51 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(int argc, char *argv[])
{
	/*
	vector<string> svec;
	string str;
	while(cin >> str)
		svec.push_back(str);

	
	for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
	*/
	list<string> slist;
	string str;
	while(cin >> str)
	{
		slist.push_back(str);
	}
	for(list<string>::iterator it = slist.begin(); it != slist.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
