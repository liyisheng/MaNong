/*************************************************************************
    > File Name: 9.38.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 06:24:08 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;


int main(int argc, char *argv[])
{
	string str("ab2c3d7R4E6");
	string num("123456789");
	string::size_type pos = 0;
	while((pos = str.find_first_of(num, pos)) != string::npos)
	{
		cout << str[pos] <<endl;
		++pos;
	}
	return 0;
}
