#include<stdio.h>
#include<stdlib.h>

#define ISLEAP(y) ( y%400 == 0 || (y%4 == 0 && y%100 != 0) )
/*
    输入两个个日期,计算间隔日期
*/
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

int between_days(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int i;
    int sum = 0;
    for( i = y1; i < y2; i++) 
    {
	if(ISLEAP(y1))
	    sum += 366;	
	else
	    sum += 365;	
    }
    sum += count_dayOfyear(y2, m2, d2) - count_dayOfyear(y1, m1, d1);
    return sum; 
}

int main()
{
    int y1,y2,m1,m2,d1,d2;
    while(scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2) == 6)
	printf("%d\n",between_days(y1,m1,d1,y2,m2,d2));
    return 0;
}

