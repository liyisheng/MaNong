/*************************************************************************
    > File Name: 10.9.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 16 Mar 2015 12:44:58 AM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

int main(int argc, char *argv[])
{
	string word;
	map<string, int> word_count;
	while(cin >> word)
		++word_count[word];
	map<string, int>::iterator it = word_count.begin();
	for(; it != word_count.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}
