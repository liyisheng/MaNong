#include<stdio.h>

#define N 8
int main() 
{
   int c; 
   int count = 0;
   int i;
   while((c = getchar()) != EOF) 
   {
	if(c != '\t')
	{
	    if( c == '\n')
	    {
		putchar(c);
		count = 0;
	    }else
	    {
		putchar(c);				
		count = (count + 1)%N;
	    }
	}else
	{
	    for(i = 0; i < N - count; i++)
		putchar(' ');
	    count = 0;
	}

   }

   return 0;

}
