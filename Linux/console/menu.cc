/*************************************************************************
    > File Name: menu.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 16时08分17秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

const char *menu[] = {
	" a - add new record",
	" b - delete record",
	" q - quit",
	NULL
};

int getchoice(const char *great, const char *choices[]);
int main(int argc, char *argv[])
{
	int choice = 0;
	do {
		choice = getchoice("Please select an action", menu);
		printf("You have chosen: %c\n", choice);
	}while(choice != 'q');
	return 0;
}

int getchoice(const char *great, const char *choices[])
{
	int chosen = 0;
	int selected;
	const char **option;

	do
	{
		printf("Choice : %s\n", great);
		option = choices;
		while(*option)
		{
			printf("%s\n", *option);
			option++;
		}

		do{
			selected = getchar();
		}while(selected == '\n');
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
			printf("Incorrect choice, select again\n");
		}

	}while(!chosen);
	return selected;
}
