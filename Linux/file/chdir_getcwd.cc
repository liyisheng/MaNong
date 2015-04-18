/*************************************************************************
    > File Name: chdir_getcwd.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 12 Apr 2015 11:23:13 PM PDT
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include<stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	chdir("./tmp");
	cout <<getcwd(NULL, 0) << endl;
	return 0;
}
