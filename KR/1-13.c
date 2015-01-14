#include<stdio.h>


int main()
{
    int c;
    int flag = 0;
    while((c = getchar()) != EOF)
    {
	if(c  == ' ' || c == '\n' || c == '\t')
	{
	    if(flag)
	    {
		putchar('\n');
		flag = 0;
	    }
	}else
	{
	    putchar(c);
	    flag = 1;
	}
    }

}
