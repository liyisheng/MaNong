/*************************************************************************
    > File Name: password.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月28日 星期二 14时59分31秒
 ************************************************************************/

#include<iostream>
#include<termios.h>
#include<stdio.h>
#include<stdlib.h>

#define PASSWORD_LEN 8
using namespace std;


int main(int argc, char *argv[])
{
	struct termios initialrsettings, newrsettings;
	char password[PASSWORD_LEN + 1];

	tcgetattr(fileno(stdin), &initialrsettings);

	newrsettings = initialrsettings;
	newrsettings.c_lflag &= ~ECHO;

	printf("Enter password :");
	if(tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings) != 0)
	{
		fprintf(stderr, "Could not set attributes\n");
	}else
	{
		fgets(password, PASSWORD_LEN, stdin);
		tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
		fprintf(stdout, "\n You entered %s\n", password);
	}
	exit(0);
	return 0;
}
