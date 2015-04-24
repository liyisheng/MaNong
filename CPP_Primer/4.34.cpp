/*************************************************************************
    > File Name: 4.34.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 20 Apr 2015 09:18:49 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(int argc, char *argv[])
{
	string str;
	vector<string> svec;
	while(cin >> str)
		svec.push_back(str);
	
	char **a = new char *[svec.size()];

	char **b = a;
	for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it, ++a)
	{
		*a = new char[(*it).size() + 1];
		strcpy(*a, (*it).c_str());
	}
	for(int i = 0; i < svec.size(); ++i)
	{
		cout << b[i] << endl;
		delete [] b[i];
	}
	delete [] b;
	return 0;
}
