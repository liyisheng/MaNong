#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
第46 题学生得记录由学号和成绩组称个，n 名大学生得数据已在主函数中放入结构体
数组s 中，请编写函数fun，它的功能时：按分数的高低排列学生的记录，高分在前
*/

typedef struct
{
    int num;
    int score;
}student;

void fun(student *s,int n)
{
    int i,j;
    student temp = {0};
    for(i = 1; i < n; i++)
	for( j = 0 ; j < n - i; j++) 
	{
	    if(s[j].score < s[j+1].score)
	    {
		temp = s[j]; 
		s[j] = s[j+1];
		s[j+1] = temp;
	    }
	}		  
}


int main()
{
    int i;
    student s[10] = {{1,69},{2,85},{3,99},{4,44},{5,66},{6,100},{7,99},{8,60},{9,50},{10,88}};
    fun(s, 10);
    for(i = 0; i < 10; i++)
    {
	printf("%d\n",s[i].score);
    }
    return 0;
}
