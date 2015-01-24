#include<stdio.h>
/*
实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
*/
char *de_leastChar(char *str)
{
    int char_num[128] = {0};  
    int min;
    int i,k = 0;
    for(i = 0; str[i] != '\0'; i++)
	char_num[str[i]]++;

    min = char_num[str[0]];
    for(i = 1; str[i] != '\0'; i++)
    {
	if(min > char_num[str[i]])
	    min = char_num[str[i]];
    }
    
    for(i = 0; str[i] != '\0'; i++)
	if(char_num[str[i]] != min)
	    str[k++] = str[i];
    str[k] = '\0';
    return str;
}
int main()
{
    char a[15000];
    gets(a);
    printf("%s\n", de_leastChar(a));
    return 0;
}



