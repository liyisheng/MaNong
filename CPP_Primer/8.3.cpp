/*************************************************************************
    > File Name: 8.3.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 12:29:18 AM CST
 ************************************************************************/

#include<iostream>
#include<stdexcept>
#include<fstream>
using namespace std;

istream&
get(istream &in)
{
	string ival;
	while(in >> ival, !in.eof())
	{
		if(in.bad())
			throw runtime_error("IO stream corrupted");
		if(in.fail())
		{
			cerr << "bad data, try again";
			in.clear();
			in.ignore(200, '\n');
			continue;
		}
		cout << ival << " ";
	}
	in.clear();
	return in;
}


int main(int argc, char *argv[])
{
	ifstream ifs("8.3.cc");
	get(ifs);
	return 0;
}
