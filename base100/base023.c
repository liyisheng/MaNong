#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
23: ��23�� ���д����fun���ú����Ĺ����ǣ��ж��ַ����Ƿ�Ϊ����?������������1��
�����������yes�����򷵻�0�������������no��������ָ˳���͵�������һ�����ַ����� 
*/

int fun(char *s)
{
    int length = strlen(s);
    int i; 
    for(i = 0; i < length/2; i++) 
    {
	if(s[i] != s[length - 1 - i])	
	    return 0;
    }
    return 1;
}

int main()
{
    char a[100];
    while(1)
    {
	scanf("%s",a);
	if(fun(a))
	    printf("yes\n");
	else
	    printf("no\n");
    }
    return 0;
}

