#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char *reverse(char *s);
void bigNum_plus(char *a, char *b, char *result);
int main()
{
    char a[] = "910812031111111111111111111111111111222222222222222222222222222222222222222234234234234";

    char b[] = "819282222222222222222222222222222333333333333333333333333333331987921213123897918239";
    char result[1000];

    gets(a);
    gets(b);
    bigNum_plus(a, b, result);
    printf("%s\n",result);
    return 0;
}


void bigNum_plus(char *a, char *b, char *result)
{
    int i;
    char flag = '0';
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max = len_a > len_b ? len_a : len_b;
    char *lit = (char *)malloc(max * sizeof(char) + 1);
    char *big = (char *)malloc(max * sizeof(char) + 1);
    char *over = (char *)malloc(max * sizeof(char) + 2);
    char *remain = (char *)malloc(max * sizeof(char) + 2);
    char *temp = (char *)malloc(max * sizeof(char) + 2);
    reverse(a);   
    reverse(b);   
    lit = (char *)malloc(max * sizeof(char) + 1);
    big = (char *)malloc(max * sizeof(char) + 1);
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
    over = (char *)malloc(max * sizeof(char) + 2);
    memset(over,'0',max + 1);
    over[max + 1] = '\0';

    remain = (char *)malloc(max * sizeof(char) + 2);
    memset(remain,'0',max + 1);
    remain[max + 1] = '\0';

    for(i = 0; i < max; i++)
    {
	remain[i] = (lit[i] - '0' + big[i] - '0')%10 + '0';
	over[i + 1] = (lit[i] - '0' + big[i] - '0')/10 + '0';
	if(over[i + 1] != '0')
	    flag = '1';
    }
    
//printf("第一次：\n%s\n", remain);    
//printf("%s\n\n", over);    

    temp = (char *)malloc(max * sizeof(char) + 2);
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

    free(lit);
    free(big);
    free(temp);
    free(over);
    free(remain);
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
