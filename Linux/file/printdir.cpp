/*************************************************************************
    > File Name: printdir.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 20 Apr 2015 03:33:42 PM CST
 ************************************************************************/

#include<iostream>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
using namespace std;

void printdir(const char *dir, int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if((dp = opendir(dir)) == NULL)
	{
		return; 
	}

	chdir(dir);
	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name))
				continue;
			printf("%*s%s/\n", depth, "",entry->d_name);
			printdir(entry->d_name, depth + 4);
		}
		else
			printf("%*s%s\n", depth, "", entry->d_name);
	}
	chdir("..");
	closedir(dp);
}

int main(int argc, char *argv[])
{

	return 0;
}
