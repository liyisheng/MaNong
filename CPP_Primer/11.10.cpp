/*************************************************************************
    > File Name: wordlen_count.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 16 Mar 2015 11:16:45 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

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
	vector<string> words;

	string next_word;
	while(cin >> next_word)
		words.push_back(next_word);

	sort(words.begin(), words.end());

	vector<string>::iterator end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	
	stable_sort(words.begin(), words.end(), isShorter);

	vector<string>::iterator it = 
		find_if(words.begin(), words.end(), GT6);

	vector<string>::size_type wc = words.end() - it;

	cout << wc << " " << "words" << " 6 characters or longer" <<endl;

	for(int j = 0; j != wc; ++j)
	{
		cout << words[words.size() - wc + j] << endl;
	}
	return 0;
}
