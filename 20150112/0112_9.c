#include<stdio.h>


char *de_space(char *src)
{
    int i;
    int state = 0;
    int k = 0;
    for(i = 0; src[i] != '\0'; i++)
    {
	if(src[i] == ' ')
	{
	    if(state == 1)
	    {
		src[k++] = ' ';
		state = 0; 
	    }
	}else
	{
	    if(state == 0)
		state = 1;
	    src[k++] = src[i];
	}
    }
    src[k] = '\0';
    return src;
}

int main()
{
    char a[100]	 = "    hello     world   how are you  ";
    printf("%s\n",de_space(a));
}
