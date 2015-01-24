#include<stdio.h>
int main()
{
    int n;
    int i, tmp;
    int count = 0;
    scanf("%d", &n);
    for(i = 7; i <= n; i++)
    {
	if(i % 7 == 0)
	{
	    count ++;
	}
	else
	{
	    for(tmp = i; tmp > 0; tmp /= 10)
		if( tmp % 10 == 7)
		{
		    count++;
		    break;
		}
	}
    }
    printf("%d\n",count);

}
