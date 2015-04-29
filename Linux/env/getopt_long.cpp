/*************************************************************************
    > File Name: getopt_long.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 11时01分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<unistd.h>
#include<cstdlib>

#include<getopt.h>
using namespace std;

int main(int argc, char *argv[])
{
	int opt;
	struct option longopts[] = {
		{"initialize", 0, NULL, 'i'},
		{"file", 1, NULL, 'f'},
		{"list", 0, NULL, 'l'},
		{"restart", 0, NULL, 'r'},
		{0, 0, 0, 0},
	};

	while((opt = getopt_long(argc, argv, ":if:lr", longopts, NULL)) != -1)
	{
		switch(opt)
		{
			case 'i':
			case 'l':
			case 'r':
				printf("option: %c\n", opt);
				break;
			case 'f':
				printf("filename: %s\n", optarg);
				break;
			case ':':
				printf("option needs a value");
				break;
			case '?':
				printf("unknown opotion: %c\n", optopt);
				break;
		}
	}

	for(; optind < argc; ++optind)
	{
		printf("argument: %s\n", argv[optind]);
	}
	return 0;
}
