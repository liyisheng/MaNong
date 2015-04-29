/*************************************************************************
    > File Name: menu.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 16时08分17秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<termios.h>
using namespace std;

const char *menu[] = {
	" a - add new record",
	" b - delete record",
	" q - quit",
	NULL
};

int getchoice(const char *great, const char *choices[], FILE*, FILE *);
int main(int argc, char *argv[])
{
	int choice = 0;

	if(!isatty(fileno(stdout)))
		fprintf(stderr, "You are not a terminal!\n");

	FILE *input = fopen("/dev/tty", "r");
	FILE *output = fopen("/dev/tty", "w");
	if(!input || !output)
	{
		fprintf(stderr, "Unable to open /dev/tty\n");
		exit(1);
	}

	struct termios initial_settings, new_settings;
	tcgetattr(fileno(input), &initial_settings);
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_lflag &= ~ISIG;

	if(tcsetattr(fileno(input), TCSANOW, &new_settings) != 0)
	{
		fprintf(stderr, "could not set attributes\n");
	}
	do {
		choice = getchoice("Please select an action", menu, input, output);
		printf("You have chosen: %c\n", choice);
	}while(choice != 'q');
	tcsetattr(fileno(input), TCSANOW, &initial_settings);
	return 0;
}

int getchoice(const char *great, const char *choices[], FILE *in, FILE *out)
{
	int chosen = 0;
	int selected;
	const char **option;

	do
	{
		fprintf(out,"Choice : %s\n", great);
		option = choices;
		while(*option)
		{
			fprintf(out,"%s\n", *option);
			option++;
		}

		do{
			selected = fgetc(in);
		}while(selected == '\n' || selected == '\r');
		option = choices;
		while(*option)
		{
			if(selected == (*option)[1])
			{
				chosen = 1;
				break;
			}
			option ++;
		}
		if(!chosen)
		{
			fprintf(out, "Incorrect choice, select again\n");
		}

	}while(!chosen);
	return selected;
}
