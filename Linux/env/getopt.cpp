/*************************************************************************
    > File Name: getopt.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 10时32分30秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
	int opt;

	while((opt = getopt(argc, argv, ":if:lr")) != -1)
	{
		switch(opt)
		{
			case 'i':
			case 'l':
			case 'r':
				printf("option: %c\n", opt);
				break;
			case 'f':
				cout << "filename :" << optarg << endl;
				break;
			case ':':
				cout << "option needs a value " << endl;
				break;
			case '?':
				cout << "unknown option : " << optopt << endl;
				break;
		}
	}

	for(; optind < argc; optind++)
		cout << "argument :" << argv[optind] << endl;
	return 0;
}
