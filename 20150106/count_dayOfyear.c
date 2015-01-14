#include<stdio.h>
#include<stdlib.h>

/*
    输入一个日期，计算其在一年中的天数
*/

int isLeap(int y)
{
    if( !(y%400) || ( (y%100)&&!(y%4) ))
	return 1;
    else
	return 0;
}

int count_dayOfyear(int day)
{
    int base[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
    int base_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31}; 
    int y,m,d; 
    int i;
    int count = 0;
    d = day % 100;
    m = (day / 100)%100;
    y = day / 10000;
    printf("%d\n",y);
    printf("%d\n",isLeap(y));
    if(isLeap(y))
    {
	for(i = 0; i < m - 1; i++) 
	   count += base_leap[i]; 
	count += d;
    }else
    {
	for(i = 0; i < m - 1; i++)	
	    count += base[i];
	count += d;
    }  
    return count; 
     
}


int main()
{
    int a;
    while(scanf("%d",&a) == 1)
	printf("%d\n",count_dayOfyear(a));
}
