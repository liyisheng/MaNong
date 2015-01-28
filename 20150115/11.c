#include<stdio.h>
#include<stdlib.h>

#define N 9

int main()
{
    int i,j;
    printf("***Pithy Formula Table of Mutiplication***\n");
    for(i = 0; i < N + 1; i++)
	if(i == 0)
	{
	    printf("\t\b");
	    for(j = 0; j < N; j++)
		printf("%3d", j+1);
	    printf("\n");
	}else
	{
	    printf("\t\b%d",i);
	    for(j = 0; j < N; j++)
		if(j == 0)
		    printf("%2d", i);
		else
		    printf("%3d", i *(j + 1));
	    printf("\n");
	}
}
