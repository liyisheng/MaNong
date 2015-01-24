#include<stdio.h>
#include<string.h>
#include<ctype.h>
/*
输入一串字符串  将字母按A-Z排序，不区分大小写。 其他字符位置不变 
例如：
A Famous Saying: Much Ado About Nothing(2012/8).
A aaAAbc dFgghh: iimM nNn oooos Sttuuuy(2012/8).

 */
int compar(char a, char b);
void str_sort(char *s);
int main()
{
    char a[1000];
    gets(a);
    str_sort(a);
    printf("%s\n",a);
}
void str_sort(char *s)
{
    int i, j, k, temp;
    int len = strlen(s);
    for(i = 1; i < len; i++)
    {
	for(j = 0, k = 1; j + k < len - i + 1;) 
	{
	   if(!isalpha(s[j]))
	    {
		j++;
		continue;
	    }
	    if(isalpha(s[j]) && !isalpha(s[j + k]))
	    {
		k++;
	    }else
	    {
		if(compar(s[j], s[j + k]) > 0)
		{
		    temp = s[j], s[j] = s[j + k], s[j + k] = temp;
		}
		j += k;
		k = 1;
	    }
	}
    }
}
int compar(char a, char b)
{
    if(a == b || a == b + 32 || a == b - 32)
	return 0;
    else if( isupper(a) && isupper(b)) 
	return a - b;
    else if(islower(a) && islower(b))
	return a - b;
    else if(islower(a) && isupper(b))
	return a - ( b + 32);
    else if(isupper(a) && islower(b))
	return a + 32 - b;
}
