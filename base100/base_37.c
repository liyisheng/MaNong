#include<stdio.h>
#include<stdlib.h>

#define  N 8

/*
第37题 某学生的记录由学号、8 门课程成绩和平均分组成，学号和8 门课程的成绩已
在主函数中给出。请编写函数fun，它的功能是：求出该学生的平均分放在记录的ave 成员
中。请自己定义正确的形参。
*/

typedef struct
{
    int num;
    int course[N];
    int ave;
}student;

void fun(student *s)
{
    double ave = 0.0;
    int i;
    for(i = 0; i < N; i++)
    {
	ave += s->course[i];
    }
    ave /= N;
    s->ave = ave;
}

int main()
{
    student a = {1, {1,2,3,4,5,6,7,8}};
    fun(&a);
    printf("%d\n",a.ave);
    return 0;
}
