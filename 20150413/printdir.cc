/*************************************************************************
    > File Name: printdir.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 12 Apr 2015 11:38:03 PM PDT
 ************************************************************************/

#include<iostream>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
using namespace std;

void printdir(char *dir, int depth)
{
	DIR *pDir;		
	pDir = opendir(dir);
	if(NULL == pDir)
	{
		cout << "error" << endl;
		return;
	}
	chdir(dir);
	struct dirent *pDirinfo;
	struct stat statbuf;
	while((pDirinfo = readdir(pDir)) != NULL)
	{
		lstat(pDirinfo->d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(".", pDirinfo->d_name) == 0 || strcmp("..",pDirinfo->d_name) == 0)
				continue;
			printf("%*s%s/\n", depth, "",pDirinfo->d_name);
			printdir(pDirinfo->d_name, depth + 4);
		}else
		{
			printf("%*s%s\n",depth,"",pDirinfo->d_name);
		}
	}
	chdir("..");
	closedir(pDir);
}
int main(int argc, char *argv[])
{
	char *topdir, pwd[2] = ".";
	if(argc < 2)
		topdir = pwd;
	else
		topdir = argv[1];
	printf("Directory scan of %s\n", topdir);
	printdir(topdir, 0);
	printf("done.\n");
	return 0;
}
