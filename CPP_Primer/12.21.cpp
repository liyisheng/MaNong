/*************************************************************************
    > File Name: 12.21.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 06:00:38 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

ifstream file("text1");
class A
{
	public:
		A(const string &s, int &ival, double *d, ifstream &ifs):
			sval(s), ival(ival), d(d), ifs(ifs){}
		A():sval("A"), ival(0), d(0), ifs(file){}
	private:
		const string sval;
		int ival;
		double *d;
		ifstream& ifs;
};
int main(int argc, char *argv[])
{
	return 0;
}
