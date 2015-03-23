/*************************************************************************
    > File Name: 12.2.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 03:35:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Person
{
	public:
		Person(const string &nm, const string &addr):
			name(nm), address(addr){
			}
		string getName() const
		{
			return name;
		}
		string getAddress() const
		{
			return address;
		}
	private: 
		string name;
		string address;
}
int main(int argc, char *argv[])
{
	return 0;
}
