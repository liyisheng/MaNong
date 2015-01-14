#include<stdio.h>
/*
   实现字符串函数： strlen(),strcpy(),strcmp(),strcat()
*/


size_t my_strlen(char *str)
{
    size_t i = 0; 
    while(str[i] != '\0')
	i++;
    return i;
}

char *my_strcpy(char *to, const char *from)
{
    int i = 0;
    while((to[i] = from[i]) != '\0')
	i++; 
    return to;
}

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    for(i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
	if(s1[i] > s2[i])	
	    return 1;
	else if(s1[i] < s2[i])
	    return -1;
	else
	    continue;
    }
    if(s1[i] == '\0' && s2[i] == '\0')
	return 0;
    else if(s1[i] != '\0')
	return 1;
    else
	return -1;
}


char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;
    while(dest[i] != '\0')
	i++; 
    while((dest[i] = src[j]) != '\0')
    {
	i++;
	j++;
    }
    return dest;
}

int main()
{
    char a[] = "abcde";
    char b[20] = "abcdef";
//    my_strcpy(b, a);
//    printf("%s\n",b);
    printf("%s\n",my_strcat(b,a));

    return 0;
}

