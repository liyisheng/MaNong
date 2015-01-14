#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char *reverse(char *s);
void bigNum_plus(char *a, char *b, char *result);
int main()
{
    char a[] = "9999991987129837017190741092730471098327499999999999";
    char b[] = "999999999999999910823749817238471298340812374070714";
    char result[100];
    bigNum_plus(a, b, result);
    printf("%s\n",result);
    return 0;
}


void bigNum_plus(char *a, char *b, char *result)
{
    int i;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max = len_a > len_b ? len_a : len_b;
    reverse(a);   
    reverse(b);   
    char *lit = (char *)malloc(max * sizeof(char) + 1);
    char *big = (char *)malloc(max * sizeof(char) + 1);
    if(max == len_a)
    {
	strcpy(big, a);
	strcpy(lit, b);
	memset(lit + len_b,'0',max - len_b);
	lit[max] = '\0';
    }else
    {
	strcpy(big, b);
	strcpy(lit, a);
	memset(lit + len_a,'0',max - len_a);
	lit[max] = '\0';
    }
 
//printf("%s\n", lit);
//printf("%s\n\n", big);
    char *over = (char *)malloc(max * sizeof(char) + 2);
    memset(over,'0',max + 1);
    over[max + 1] = '\0';

    char *remain = (char *)malloc(max * sizeof(char) + 2);
    memset(remain,'0',max + 1);
    remain[max + 1] = '\0';

    char flag = '0';
    for(i = 0; i < max; i++)
    {
	remain[i] = (lit[i] - '0' + big[i] - '0')%10 + '0';
	over[i + 1] = (lit[i] - '0' + big[i] - '0')/10 + '0';
	if(over[i + 1] != '0')
	    flag = '1';
    }
    
//printf("第一次：\n%s\n", remain);    
//printf("%s\n\n", over);    

    char *temp = (char *)malloc(max * sizeof(char) + 2);
    memset(temp,'0',max + 1);
    temp[max + 1] = '\0';
    while(flag != '0')
    {
	flag = '0';
	strcpy(temp, over);
	for(i = 0; i <= max; i++)
	{
	    over[i + 1] = (remain[i] - '0' + temp[i] - '0')/10 + '0';
	    remain[i] = (remain[i] - '0' + temp[i] - '0')%10 + '0';
	    if(over[i + 1] != '0')
		flag = '1';
	}
    }
    
    reverse(remain);
    if(remain[0] == '0')
	strcpy(result, remain + 1);
    else
	strcpy(result, remain);

}


char *reverse(char *s)
{
    int i,j; 
    int c;
    for(i = 0 , j = strlen(s) - 1; i < j; i++,j--)
    {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
    }
    return s;
}
