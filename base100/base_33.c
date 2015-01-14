#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define N 5
/*
33: 第33题 假定输入的字符串中只包含字母和*号。请编写函数fun，它的功能是：
使字符串中尾部的*号不得多于n个；若多于n个，则删除多于的*号；若少于或等于n个，则什么也不做，字符串中间和前面的*号不删除。 
*/

char *fun(char *s, char *t )
{
    int length = strlen(s); 
    int i; 
    int count = 0;
    int index = 0;
/*
    for(i = 0; i < length; i++)
    {	
	if(s[i] == '*')
	    count++;	
	if(s[i] == '*' && count > N)
	    continue; 
	else
	   t[index++] = s[i];
    }
    t[index] = '\0';
 */    
    while( s[--length] == '*')
    {
	count ++;
    }
    printf("count: %d\n",count);
    if(count <= N)
	return s; 
    else
    {
	for(i = 0; i <= length + N; i++)
	{	
	    t[index++] = s[i];
	}
	return t;
    }
}

int main()
{
    char s[] = "abcd*ef*gh*i*j*kk*llm*opp**qrs**t****************";
    char t[100] = "";
    printf("%s\n",s);

    printf("%s\n",fun(s,t));
    printf("%s\n",t);
    return 0;
}
