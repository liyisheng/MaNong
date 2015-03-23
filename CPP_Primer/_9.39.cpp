/*************************************************************************
    > File Name: 9.39.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 06:30:37 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{

	string line1 = "We were her pride of 10 she named us:";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";

	string sentence = line1 + ' ' + line2 + ' ' + line3;
	cout << sentence;	

	string separators(" \t:,\v\r\n\f");

	string::size_type startPos = 0, endPos = 0;
	string::size_type maxLen, minLen, wordLen, count = 0;

	vector<string> longestWords, shortestWords, words;
	string word;
	while((startPos = sentence.find_first_not_of(separators, endPos)) != string::npos)
	{
		++count;
		endPos = sentence.find_first_of(separators,startPos);	
		if(endPos == string::npos)	
			wordLen = sentence.size() - startPos;
		else
			wordLen = endPos - startPos;

		word.assign(sentence.begin() + startPos, sentence.begin() + startPos + wordLen);  
		words.push_back(word);
		if(count == 1)
		{
			maxLen = minLen = wordLen;
			longestWords.push_back(word);
			shortestWords.push_back(word);
		}else
		{
			if(wordLen > maxLen)	
			{
				maxLen = wordLen;
				longestWords.clear();
				longestWords.push_back(word);
			}else if(wordLen == maxLen)
			{
				longestWords.push_back(word);
			}

			if(wordLen < minLen)
			{
				minLen = wordLen;
				shortestWords.clear();
				shortestWords.push_back(word);
			}else if(wordLen == minLen)
				shortestWords.push_back(word);
		}
	}

	cout << "word count: " << count << endl;
	vector<string>::iterator it;
	cout << "longest word(s) : " << endl;
	for(it = longestWords.begin(); it != longestWords.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "shortest word(s): " << endl;
	for(it = shortestWords.begin(); it != shortestWords.end(); ++it)
		cout << *it << endl;

	cout <<endl;
	for(it = words.begin(); it != words.end(); ++it)
		cout << *it << endl;
			
		return 0;
}
