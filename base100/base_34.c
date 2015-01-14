#include<stdio.h>
#include<stdlib.h>

/*
第34题 学生的记录由学号和成绩组成，n名学生的数据已在主函数中放入结构体数组s中，请编写函数fun，
它的功能使：把分数最高的学生数据放在h所指的数组中，注意：分数最高的学生可能不止一个，函数返回分数最高的学生的人数。 
*/

typedef struct
{   
    int num;
    int score;
}student;

int fun(student *a, student *b,int n)
{
    int i;
    int max = a[0].score;
    int index = 0;
    for(i = 0; i < n; i++)
    {
	if(a[i].score > max)
	    max = a[i].score;	
    }
    for(i = 0; i < n; i++)
    {
	if(a[i].score == max)
	b[index++] = a[i];
    }
    return index;
    
}

int main()
{
    int i;
    student a[] = {{1,88},{2,88},{3,77},{4,66},{5,88}};
    student b[5]; 
    printf("%d\n",fun(a,b,5));	
    return 0;
}
