/*************************************************************************
    > File Name: io1.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 07 Mar 2015 11:15:04 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

void printCin()
{
	cout << "bad = " << cin.bad() << endl;
	cout << "fail = " << cin.fail() << endl;
	cout << "eof = " << cin.eof() << endl;
	cout << "good = " << cin.good() << endl << endl;
}

int main(int argc, char *argv[])
{
	int inum;
	printCin();

	while(cin >> inum)
	{
		cout << inum << endl;
	}

	printCin();
	cin.clear();

	printCin();
	//cin.ignore(1024, '\n');

	string s;
	cin >> s;
	cout << s << endl;
	return 0;
}
