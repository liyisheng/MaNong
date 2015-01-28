#include<stdio.h>

#define ISLEAP(y) ( y%400 == 0 || (y%4 == 0 && y%100 != 0) )

int count_dayOfyear(int y,int m, int d);
int between_days(int y1, int m1, int d1, int y2, int m2, int d2);

int main()
{
    int y, m, d;
    while(1)
    {
	printf("请输入年/月/日【输入1990 1 1 退出】:");
	scanf("%d%d%d", &y, &m, &d);	
	if(y == 1990 && m == 1 && d == 1)
	    break;
	
	if( y < 1970)
	{
	    printf("对不起，那一年他还没出生呢! 按任意键继续...\n");
	    getchar();
	    continue;
	}else if( y < 1990)
	{
	    printf("对不起，那一年他还没开始打鱼呢! 按任意键继续...\n");
	    getchar();
	    continue;
	}else
	{
	    if(between_days(1990, 1, 1, y, m, d)%5 >= 3)
		printf("%d年%d月%d日，他正在晒网。\n", y, m, d);
	    else
		printf("%d年%d月%d日，他正在打鱼。\n", y, m, d);
	}
    }

}


int between_days(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int i;
    int sum = 0;
    for( i = y1; i < y2; i++)
    {
	if(ISLEAP(i))
	    sum += 366;
	else
	    sum += 365;
    }
    sum += count_dayOfyear(y2, m2, d2) - count_dayOfyear(y1, m1, d1);
    return sum;
}
int count_dayOfyear(int y,int m, int d)
{
    int i;
    int count = 0;
    for(i = 1; i < m; i++)
    {
	switch(i)
	{
	    case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
		count += 31;
		break;
	    case 4:
	    case 6:
	    case 9:
	    case 11:
		count += 30;
		break;
	    case 2:
		if(ISLEAP(y))
		    count += 29;
		else
		    count += 28;
		break;
	    default:
		break;
	}
    }
    count += d;
    return count;

}
