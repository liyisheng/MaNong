#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
第32题 请编写函数fun，其功能是：将s所指字符串中除了下标为奇数、同时ascii值也为奇数的字符之外，其余的所有字符都删除，串中剩余字符所形成的一个新串放在t所指的一个数组中。 
*/

void fun(char *s, char *t)
{
    int length = strlen(s); 
    int i; 
    int index = 0;
    for(i = 1; i < length; i+=2)
    {		
	if((s[i]%2))	
	    t[index++] = s[i];	
    }
    t[index] = '\0';
}


int main()
{
    char *s = "Aabcdefghijklmn"; 
    char t[30] = "";
    fun(s,t);
    
    printf("%s\n",t);
    return 0;
}
