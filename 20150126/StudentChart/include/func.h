/*************************************************************************
    > File Name: func.h
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 26 Jan 2015 07:36:39 PM CST
 ************************************************************************/

#ifndef _FUNC_H
#define _FUNC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_SIZE 100
typedef struct tag
{
	int row, col;
	char name[100];
	struct tag *right; 
	struct tag *down; 
}Node,*pNode,*OLink; 
typedef struct 
{
	OLink *row_head;// 行、列链表的头指针数组
	OLink *col_head;
	int m,n,len;//行数、列数、非零元素个数
}CrossLink;

void CreateCrossList(CrossLink *l, int m, int n);
int InsertCrossList(CrossLink *l, int row, int col, char *data);

int loadStuChartFile(char *file, CrossLink *l);
int getValueByDelim(char *sSrc, char *sDest, char *sDelim);
void PrintCrossList(CrossLink *l);
void PrintRow(CrossLink *l, int row);
#endif
