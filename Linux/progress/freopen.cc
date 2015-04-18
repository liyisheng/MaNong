/*************************************************************************
    > File Name: freopen.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 16 Apr 2015 04:12:26 AM PDT
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	freopen("myfile.txt", "r", stdin);
		
	fclose(stdout);
	return 0;
}
