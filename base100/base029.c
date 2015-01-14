#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
第29题 请编写一个函数fun，它的功能是：
将ss所指字符串中所有下标为奇数位置上的字母转换为大写(若该位置上不是字母，则不转换)。 
*/

char *fun(char *ss)
{
    int i;
    int length = strlen(ss); 
    printf("字符串长度：%d\n", length);
    for(i = 1; i < length; i+=2)
    {
	if(ss[i] >= 'a' && ss[i] <= 'z')			
	    ss[i] -= 32;
    }
    return ss;
}


int main()
{
    char a[] = "$aBcDeFgHiJkLmNoPqRsTuVwXyZ";
    printf("%s\n",fun(a));
    return 0;
}
