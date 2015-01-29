#ifndef MY_LS
#define MY_LS
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>
#include<dirent.h>
void show_info(char* path);
#endif
