/*************************************************************************
    > File Name: main.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 26 Jan 2015 07:39:29 PM CST
 ************************************************************************/

#include<func.h>

int main()
{
	char *file1 = "/home/lys/manong/20150126/StudentChart/data/col_3.csv";
	char *file2 = "/home/lys/manong/20150126/StudentChart/data/col_0.csv";
	char *file3 = "/home/lys/manong/20150126/StudentChart/data/col_1.csv";
	char *file4 = "/home/lys/manong/20150126/StudentChart/data/col_2.csv";
	CrossLink List;	
	CreateCrossList(&List, 8, 9);
	loadStuChartFile(file1, &List);
	loadStuChartFile(file2, &List);
	loadStuChartFile(file3, &List);
	loadStuChartFile(file4, &List);

	PrintCrossList(&List);
}
