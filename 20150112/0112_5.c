#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
将字符串翻转
*/


char *reverse(char *src)
{
    int i,j;
    int count = 0;
    int state;
    int length = strlen(src);
    char *temp = (char *)malloc(length * sizeof(char) + 1);
    strcpy(temp, src);

    state = 0;
    for(i = 0; temp[i] != '\0'; i++)
    {
	if(temp[i] == ' ')
	{
	    state = 0;
	    src[length - 1 - i] = ' ';
	}
	else
	{
	    if(state = 1)
		state = 0;	
	    count++;
	    if(temp [i + 1] == ' ' || temp [i + 1] == '\0')
	    {
		j = 0;
		while(count)
		{
		    src[length - 1 - i + j] = temp[i + 1 - count];
		    count--;
		    j++;
		}
	    }
	}
    }
    free(temp);
    return src;
}

int main()
{
    char a[100] = " I am a student  how are you  ";

    printf("%s\n",reverse(a));
    return 0;
}
