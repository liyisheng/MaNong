#include<stdio.h>

#define N 100
#define IN 1
#define OUT 0
int main()
{
    char a[N];
    
    while(gets(a))
    {
	printf("%d\n",count_word(a));
    }

    return 0;
}

int count_word(const char a[])
{
    int i,state,count = 0;
    state = OUT;
    for(i = 0; a[i] != '\0'; i++)
	if(a[i] == ' ' || a[i] == '\t')	
	    state = OUT;
	else	
	    if(state == OUT)
	    {	
		count ++;
		state = IN;
	    }
	    if(state == IN)	
		putchar(a[i]);
    return count;
}
