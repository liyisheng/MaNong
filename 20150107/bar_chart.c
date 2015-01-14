#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[100];
    int i,j;
    int max;
    int base[3] = {0};
    scanf("%s",s);
    for(i = 0; i < strlen(s); i++)
    {
	if(((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')))
	    base[0]++;
	else if((s[i] >= '0') && (s[i] <= '9'))
	    base[1]++;
	else
	    base[2]++;
    }
    max = base[0];
    for(i = 0; i < 3; i++)
    {	
	printf("%d\t",base[i]);
	if(max < base[i])
	    max = base[i];
    }
    printf("\n");
    for(i = 0 ; i < max; i++)  
    {
	for(j = 0; j < 3; j++)
	{
	    if(base[j] == max)	
	    {
		printf("*****\t");
	    }else
	    {
		printf("     \t");
		base[j]++; 
	    }
	}
	printf("\n");
    }
    return 0;
}
