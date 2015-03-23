/*************************************************************************
    > File Name: 3.14.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 14 Mar 2015 11:21:38 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

int main(int argc, char *argv[])
{
	vector<string> svec;
	string str;
	cout << "Enter text(Ctrl + D to end):" <<endl;
	while(cin >>str)
		svec.push_back(str);

	if(svec.size() == 0)
	{
		cout << "No String" << endl;
		return -1;
	}
	for(vector<string>::size_type ix = 0; ix != svec.size(); ++ix)
	{
		for(string::size_type i = 0; i != svec[ix].size(); i++)
		{
			if(islower(svec[ix][i]))
			{
				svec[ix][i] = toupper(svec[ix][i]);
			}
		}
		cout << svec[ix] << " ";
		if((ix + 1) % 8 == 0)
			cout << endl;
	}
	return 0;

}
