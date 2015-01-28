#include<stdio.h>
#include<string.h>




int isSubstring(char *str, char *substr)
{
    int i,j;
    int len_str = strlen(str);
    int len_sub = strlen(substr);
    if(len_sub > len_str)
	return 0;
    for(i = 0; i < len_str - len_sub; i++)
    {
	if(str[i] != substr[0])
	    continue;
	if(memcmp(&str[i], substr, len_sub) == 0)
		return 1;
    }
    return 0;
}

int main()
{
    char a[1000];
    char b[1000];
    scanf("%s", a);
    scanf("%s", b);
    printf("%d\n", isSubstring(a ,b));
    return 0;
}
