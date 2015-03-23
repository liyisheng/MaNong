/*************************************************************************
    > File Name: 9.40.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 07:44:26 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	string q1("When lilace last in the dooryard bloom'd");
	string q2("The child is father of the man");

	string sentence;
	sentence.assign(q2.begin(),  q2.begin() + 13);
	sentence.append(q1, q1.find("in"), 15);

	cout << sentence << endl;
	return 0;
}
