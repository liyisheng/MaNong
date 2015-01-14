#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
第44 题编写一个函数，该函数可以统计一个长度为2 的字符串在另一个字符串中出现
的次数。
*/


int fun(char *a, char *s)
{
    int i,j;
    int count = 0;
    int length = strlen(s); 
    int base = strlen(a); 
    i = 0;
    while(i <= length-base)
    {
	if(s[i] == a[0])	
	{
	    for(j = 0; j < base; j++)
		if(s[i+j] == a[j])   
		    continue;	
		else
		    break;
	    if(j == base)
	    {
		count++;
		i += j;
	    }else
		i++; 
	}else
	    i++;
    }
    return count;
}




int main()
{

    char s[] = "abababaBBabaBBabaabaBBaba";
    char a[] = "aba";
    printf("%d\n",fun(a,s));
    return 0;
}

