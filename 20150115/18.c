#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000

int main()
{
    fun(10);

}



int fun(int n)
{
    int i = 0;
    int k;
    char s[N] = "1";
    char tmp[N];
    //memset(s, 0, N);
    while(n > 0)
    {
	k = 0;
	for(i = 0; s[i] != '\0'; i++)
	{
	    if(s[i + 1] == s[i])	
	    {
		if(s[i + 2] == s[i])
		{
		    i += 2;
		    tmp[k++] = '3', tmp[k++] = s[i];
		}
		else
		{
		    i++;
		    tmp[k++] = '2', tmp[k++] = s[i];
		}

	    }else
	    {
		tmp[k++] = '1', tmp[k++] = s[i];
	    }
	}
	tmp[k] = '\0';
	strcpy(s, tmp);
	printf("%s\n", s);
	n--;
    }
}

