/*************************************************************************
    > File Name: 3.10.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 13 Mar 2015 08:37:06 PM CST
 ************************************************************************/

#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
	string s;
	string result;
	cin >> s;
	string::iterator it = s.begin();	

	for(; it != s.end();)
	{
		if(ispunct(*it))	
		{
			s.erase(it);
		}else
			it++;
	}
	
	/*
	for(int i = 0; i < s.size(); i++)
	{
		if(!ispunct(s[i]))	
			result += s[i];
	}
	*/
	cout << s << endl;
		
	return 0;
}
