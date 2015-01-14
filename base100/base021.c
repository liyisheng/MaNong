#include<stdio.h>
#include<stdlib.h>

#define N 7
/*
21: 第21题 请编写函数fun,对长度为7个字符的字符串，除首尾字符外，将其余5个字符按ascii码降序排列。
*/

void fun(char *s)
{
    int i,j,temp;
    for(i = 1; i < N-2; i++) 
	for(j = 1; j < N - 1 - i; j++) 
	{
	    if(s[j] < s[j + 1])	
	    {
		temp = s[j];
		s[j] = s[j + 1];
		s[j + 1] = temp;
	    } 
	}
}

int main()
{
    char s[] = "GabcdeH";
    printf("%s\n",s); 
    fun(s);
    printf("%s\n",s); 
    return 0;
}
