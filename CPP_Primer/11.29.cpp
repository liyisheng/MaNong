/*************************************************************************
    > File Name: 11.29.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 08:49:06 PM CST
 ************************************************************************/

#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
bool GT6(const string &s)
{
	return s.size() >= 6;
}

int main(int argc, char *argv[])
{
	list<string> words;
	
	string next_word;
	while(cin >> next_word)
		words.push_back(next_word);

	words.sort();
	words.unique();

	list<string>::size_type wc = count_if(words.begin(), words.end(), GT6);
	cout << wc;

	return 0;
}
