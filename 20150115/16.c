#include<stdio.h>
#include<ctype.h>



void fun(char *s, char *s1)
{
    int i, j, k = 0;
    int state = 0;
    int blank_num;
    int word_num = count_blank(s, &blank_num);
    int len = blank_num / word_num;
    int last_len = blank_num % word_num;
    for(i = 0; s[i] != '\0'; i++)
    {
	if(s[i] == ' ' || s[i] == '\t') 
	{
	    if(state == 1)	
	    {
		for(j = 0; j < len; j++)
		    s1[k++] = ' ';
		state = 0;
	    }
	}else
	{
	    if(state == 0)
		state = 1;
	    s1[k++] = s[i];
	}
    }
    s1[k] = '\0';
}


int count_blank(const char *s, int *blank_num)
{
    int i;
    int tab_count = 0; 
    int count = 0;
    int count_wd = 0;
    int state = 0;
    for(i = 0; s[i] != '\0'; i++)
    {
	if(s[i] == ' ')
	{
	    state = 0;
	    count++;
	    tab_count++;
	}else if( s[i] == '\t')
	{
	    state = 0;
	    count += (8 - tab_count); 
	    tab_count = 0;
	}else
	{
	    if(state == 0)
	    {
		state = 1;
		count_wd++;
	    }
	    tab_count++;
	}
    }
    *blank_num = count;
    return count_wd;
}

int main()
{
    int blank_num;
    char a[1000];
    char s[1000];
    gets(a);
    fun(a, s);
    int count_wd = count_blank(a, &blank_num);
    printf("%d  %d\n", blank_num, count_wd);
    printf("%s\n", s);
    return 0;
}



