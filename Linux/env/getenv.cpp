/*************************************************************************
    > File Name: getenv.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 12时33分15秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
	char *var, *value;

	if(argc == 1 || argc > 3)
	{
		cerr << "error!" << endl;
		exit(1);
	}

	var = argv[1];

	value = getenv(var);
	if(value)
		cout << "value : " << value << endl;
	else
		cout << "no value!" << endl;


	if(argc == 3)
	{
		string str(var);
		value = argv[2];
		str = str + '=' + value;
		cout << "calling putenv :" << str << endl;

		if(putenv(const_cast<char*>(str.c_str())) != 0)
		{
			cout << "putenv failed" << endl;
			exit(1);
		}

		value = getenv(var);
		if(value)
			cout << "value : " << value << endl;
		else
			cout << "no value!" << endl;

	}
	return 0;
}
