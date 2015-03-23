/*************************************************************************
    > File Name: 9.41.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 09:12:21 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string
greet(string form, string lastname, string title, string::size_type pos, int length);

int main(int argc, char *argv[])
{
	string generic1("Dear Ms Daisy:");
	string generic2("MrsMsMissPeople");

	string lastName("AnnaP");
	string salute = greet(generic1, lastName, generic2, 5, 4);

	cout << salute << endl;
	return 0;
}
string
greet(string form, string lastname, string title, string::size_type pos, int length)
{
	form.replace(form.find("Daisy"), 5, lastname);
	form.replace(form.find("Ms"), 2, title, pos, length);
	return form;
}
