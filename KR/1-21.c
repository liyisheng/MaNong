#include<stdio.h>

#define TAB 8
int main()
{
    int c;       
    int cnt_tab = 0;
    int	cnt_space = 0; 
    int pos = 1;
    while((c = getchar()) != EOF)
    {
	if(c == ' ')	
	{
	    if(pos%TAB!=0) 
		cnt_space++;		
	    else
	    {
		cnt_space = 0;
		cnt_tab++;
	    }
	}else
	{
	    while(cnt_tab)
	    {
		putchar('\t');
		cnt_tab--;
	    }
	    if(c == '\t')
		cnt_space = 0;
	    else
		while(cnt_space)
		{
		    putchar(' ');
		    cnt_space--;
		}
	    putchar(c);
	    if(c == '\n')
		pos = 0;
	    else if(c == '\t')
		pos = pos + (TAB - (pos - 1)%TAB) - 1;
	}
	pos++;
    }
}
