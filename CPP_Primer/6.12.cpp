/*************************************************************************
    > File Name: 6.12.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 21 Apr 2015 03:02:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string preStr, curStr;
	string maxStr;
	int curNum = 0, maxNum = 1;


	while(cin >> curStr)
	{
		if(curStr == preStr)
			++curNum;
		else
		{
			if(curNum > maxNum)
			{
				maxStr = preStr;
				maxNum = curNum;
			}
			curNum = 1;
			preStr = curStr;
		}
	}

	if(maxNum != 1)
	{
		cout << maxStr << "  " << maxNum << endl;
	}else
		cout << "no repeate!\n";
	return 0;
}
