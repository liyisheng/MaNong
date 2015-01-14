#include<stdio.h>

typedef char * String;

int CalcCapital(String str)
{
    int i;
    int count = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
	if(str[i] >= 'A' && str[i] <= 'Z')
	    count++;
    }
    return count;
}


int main()
{
    char a[100];
    gets(a);
    printf("%d\n",CalcCapital(a));

    return 0;
}

