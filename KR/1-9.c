#include<stdio.h>


int main()
{
    int c;
    int flag = 1;
    while((c = getchar()) != EOF)
    {
	if(c == ' ')
	{
	    if(flag == 1)
	    {
		putchar(c);
		flag = 0;
	    }else 
		;
	}else
	{
	    putchar(c);
	    flag = 1;
	}
    }

}

