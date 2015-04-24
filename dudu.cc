/*************************************************************************
    > File Name: dudu.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 19 Apr 2015 09:16:09 PM CST
 ************************************************************************/

#include<iostream>
#include<ctype.h>
#include<vector>
using namespace std;

int isequal(char &a, char &b);
int countBB(string &s);
int main(int argc, char *argv[])
{
	int num;
	cin >> num;
	string str;
	vector<string> svec;
	for(int i = 0; i < num; ++i)
	{
		cin >> str;
		svec.push_back(str);
	}
	for(vector<string>::iterator it = svec.begin();
			it != svec.end(); ++it)
	{
		cout << countBB(*it) <<endl;
	}
	return 0;
}

int countBB(string &s)
{
	int num = isupper(s[0]) ? 2*(s[0] - 'A' + 1 ) : (s[0] - 'a' + 1);
	int count = isupper(s[0]) ? 2 : 1;
	int quan;
	if(s.size() == 0)
		return 0;
	else if(s.size() == 1)
		return num *count; 
	else
		quan = 0;
	for(int i = 1; i < s.size(); ++i)
	{
		if(isequal(s[i], s[i - 1]) == 1)
		{
			num += 2*(s[i] - 'A' + 1);
			count += 2;
		}else if(isequal(s[i], s[i - 1]) == 2)
		{
			num += s[i] - 'a' + 1;
			count ++;
		}
		else
		{
			num *= count;
			quan += num;	
			num = isupper(s[i])? 2*(s[i] -'A' + 1) : (s[i] - 'a' + 1);
			count = isupper(s[i]) ? 2 : 1;
		}
	}
	quan += num * count;
	return quan;
}

int isequal(char &a, char &b)
{
	if(isupper(a) && (a == b))
		return 1;
	else if(isupper(a) && (b == a + 32))
		return 1;
	else if(isupper(b) && (a == b + 32))
		return 2;
	else if(islower(a) && a == b)
		return 2;
	else
		return 0;
}
