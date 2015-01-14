#include<stdio.h>

/*
函数any(s1,s2), 将字符串s2中的任一字符在字符串s1中第一次出现的位置作为结果返回.
如果s1中不包含s2中的字符，则返回-1
*/

int any(char s1[], char s2[])
{
    int i, j;
    for(i = 0; s1[i] != '\0'; i++)
	for(j = 0; s2[j] != '\0'; j++)
	    if(s2[j] = s1[i])
		return i;
    return -1;
}















