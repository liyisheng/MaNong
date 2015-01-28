#include<stdio.h>
#include<stdlib.h>
int isLeap(int);
int week(int, int, int);
void calendar(int y)
{
    char *t = "Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa";
    char *jm[] = {"      January               February               March ","       April                  May                   June","        July                 August              September","      October               November              December"};
    int i,o, p, q;
    int m = 0; 
    int d[12] = {1,1,1,1,1,1,1,1,1,1,1,1}; 
    int base[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int base_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int isLeapYear = isLeap(y);
	printf("%32d\n",y);
	for(q = 0; q < 4; q++)
	{
		printf("%s\n",jm[q]);
		printf("%s\n",t);
		for(p = 0; p < 6; p ++)
		{
			m = 3*q;
			for( o = 0; o < 3; o++) 
			{
				for( i = 0; i < 7; i++)
				{
					if( i < week(y,m+1,d[m]) )
						printf("  ");
					else
					{
						if(isLeapYear)
						{
							if(d[m] <= base_leap[m])
								printf("%2d", d[m]++);
							else
								printf("  ");
						}else
						{
							if(d[m] <= base[m])
								printf("%2d", d[m]++);
							else
								printf("  ");
						}
					}
					printf(" ");
				}
				printf(" ");
				m++;
			}
			printf("\n");
		}
	}
	printf("\n"); 
}
/*
   0,1,2,3,4,5,6,分别对应星期一、二、三、四、五、六、日
   */
int week(int y, int m, int d)
{
	if(m == 1 || m ==2)
	{
		m += 12;
		y--; 
    }
    return ((d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) + 1)%7; //基姆拉尔森计算公式(根据日期计算星期）
}
int isLeap(int y)
{
    if( !(y%400) || ( (y%100)&&!(y%4) ))
        return 1;
    else
        return 0;
}
int main()
{
	int y;
	scanf("%d", &y);
    calendar(y); 
    return 0;
}
