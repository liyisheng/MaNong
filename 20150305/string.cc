/************************************************************************* > File Name: string.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Mar 2015 11:38:42 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	string s1 = "abcefg";
	string s2("hello,world");

	string s3 = s1 + s2;

	char ch = 'E';

	string s4 = s2 + ch;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;


	string s5 = s2.substr(0,5);
	string s6 = s2.substr(6,5);

	cout << s5 << endl;
	cout << s6 << endl;


	string::iterator it = s2.begin();
	for(; it != s2.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
