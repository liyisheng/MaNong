/*************************************************************************
    > File Name: io2.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 07 Mar 2015 11:21:02 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int ival;
	while(cin >> ival, !cin.eof())
	{
		if(cin.bad())
		{
			cout << "IO stream corrupted! " << endl;
		}

		if(cin.fail())
		{
			cout << "data illegal, try again!" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		cout << "ival = " << ival << endl;
	}
	return 0;
}
