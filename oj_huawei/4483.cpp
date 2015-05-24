/*************************************************************************
  > File Name: 4483.cpp
  > Author: liyisheng
  > Mail: liyishengchn@gmail.com 
  > Created Time: Tue 05 May 2015 01:50:05 PM CST
 ************************************************************************/
#include<iostream>
#include<sstream>
#include<map>
#include<set>
using namespace std;

int main()
{

	int n;
	ostringstream ssout;
	istringstream ssin;
	string s;
	int temp, temp2 = 0;
	map<int, int > imap;
	set<int> isec;

	cin >> n;
	if (n < 0)
		n = -n;
	ssout << n;
	s = ssout.str();
	for (string::size_type i = 0; i < s.size(); ++i)
	{

		string::size_type j = i;
		temp2 = s[j] - '0';
		while (j < s.size() - 1 && s[j + 1] < s[j])
		{

			j++;
			temp2 += s[j] - '0';
		}
		if (j > i)
		{

			ssin.str(s.substr(i, j - i + 1));
			ssin >> temp;
//			ssin.clear();
			imap.insert(make_pair(temp2, temp));
			isec.insert(temp);
		}
	}

	cout <<  imap.rbegin()->second + *(isec.rbegin());
	return 0;
}
