#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
19: ��19�� ��д����fun,�ú����Ĺ����ǣ����ַ���ɾ��ָ�����ַ���ͬһ��ĸ�Ĵ�Сд����ͬ�ַ�����
*/

void fun(char s[], char c)
{
    int i = 0;
    int j;
    int length = strlen(s);
    while(s[i] != '\0')
    {
	if(s[i] == c)
	{
	    for(j = i; j < length-1; j++) 
	    {
		s[j] = s[j + 1];
		s[length-1] = '\0';
	    }
	} 
	i++;
    }
}


int main()
{
    char s[] = "abcedfajoguouHoiabaouOUUo";
    printf("%s\n", s);
    fun(s, 'a');
    printf("%s\n", s);
    return 0;
}

