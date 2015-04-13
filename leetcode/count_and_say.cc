/*************************************************************************
    > File Name: count_and_say.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 09 Apr 2015 11:35:07 PM PDT
 ************************************************************************/

#include<iostream>
#include<sstream>
using namespace std;


string convert(const string &say)
{
	stringstream ss; 
	int count = 0;
	char last = say[0];
	for(size_t i = 0; i <= say.size(); ++i)
	{
		if(say[i] == last)
		{
			++count;
		}else
		{
			ss << count << last;
			count = 1;
			last = say[i];
		}
	}
	return ss.str();
}
string countAndSay(int n)
{
	if(n <= 0)
		return string();
	string say = "1";
	for(int i = 1; i < n; ++i)
		say = convert(say);
	return say;
}

int main(int argc, char *argv[])
{
	cout << countAndSay(4);
	return 0;
}
