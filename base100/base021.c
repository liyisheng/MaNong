#include<stdio.h>
#include<stdlib.h>

#define N 7
/*
21: ��21�� ���д����fun,�Գ���Ϊ7���ַ����ַ���������β�ַ��⣬������5���ַ���ascii�뽵�����С�
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
