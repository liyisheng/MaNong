/*************************************************************************
    > File Name: opendir.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 12 Apr 2015 11:32:00 PM PDT
 ************************************************************************/

#include<iostream>
#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	struct dirent *pDirinfo;
	DIR *pDir;
	if(argc < 2)
		pDir = opendir(".");
	else
		pDir = opendir(argv[1]);
	if(NULL == pDir)
	{
		perror("open dir fail!");
		return -1;
	}

	while((pDirinfo = readdir(pDir)) != NULL)
		cout << pDirinfo->d_name << endl;
	closedir(pDir);
	return 0;
}
