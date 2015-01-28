/*************************************************************************
    > File Name: Kaprekar_number.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 26 Jan 2015 11:16:09 AM CST
 ************************************************************************/
/*
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort_bubble(char *a, int len);
void sort_bubble_max(char *a, int len);
int prove_Kaprekar(int n);
int main()
{
	prove_Kaprekar(4312);
	return 0;
}
int i = 1;
int prove_Kaprekar(int n)
{
	char a[5];		
	int min, max;
	sprintf(a, "%d", n);
	sort_bubble(a, 4);
	min = atoi(a);
	sort_bubble_max(a, 4);
	max = atoi(a);
	printf("Step No.%d %d-%d = %d\n", i, max, min, max -min);
	if((max - min) == 6174)
		return 1;
	else
	{
		i++;
		prove_Kaprekar(max - min);
	}
}
void sort_bubble(char *a, int len)
{
    int i,j; 
	int tmp;
	for(i = 1; i < len; i++)
		for(j = 0; j < len - i; j++)
			if(a[j] > a[j + 1]) 
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
}
void sort_bubble_max(char *a, int len)
{
    int i,j; 
	int tmp;
	for(i = 1; i < len; i++)
		for(j = 0; j < len - i; j++)
			if(a[j] < a[j + 1]) 
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
}
