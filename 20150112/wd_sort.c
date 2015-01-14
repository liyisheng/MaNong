#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define N 100
#define M 100
#define IN 1
#define OUT 0
void sort_bubble(char *a[], int len);
void wd_extract(const char a[], char *b[]);
int count_word(const char a[]);
int word_num(const char a[], int *b);
int main()
{
    char a[N];
    int *b;
    char **c; 
    int i;
    int wd_num;
    while(gets(a))
    {
	wd_num = count_word(a);
	b = (int *)malloc(wd_num * sizeof(int));
	word_num(a, b);	
	for(i = 0; i < wd_num; i++)
	    printf("%d ",b[i]);
	printf("\n");

	c = (char **)malloc(wd_num * sizeof(char *));
	for(i = 0; i < wd_num; i++)
	    c[i] = (char *)malloc(b[i] * sizeof(char) + 1);

	wd_extract(a, c);
	sort_bubble(c, wd_num);
	for(i = 0; i < wd_num; i++)
	    printf("%s\n",c[i]);

	for(i = 0; i < wd_num; i++)
	    free(c[i]);
	free(c);

    }


    return 0;
}
/*
   提取单词
 */
void wd_extract(const char a[], char *b[])
{
    int i,j,state,count = 0;
    state = OUT;
    for(i = 0; a[i] != '\0'; i++)
	if(a[i] == ' ' || a[i] == '\t')	
	    state = OUT;
	else	
	{
	    if(state == OUT)
	    {	
		count++;
		state = IN;
		j = 0;
	    }
	    b[count-1][j++] = a[i];
	    if(a[i + 1]  == ' ' || a[i + 1] == '\t')
		b[count - 1][j] = '\0';
	}
}

/*
统计输入行 单词个数
 */
int count_word(const char a[])
{
    int i,state,count = 0;
    state = OUT;
    for(i = 0; a[i] != '\0'; i++)
	if(a[i] == ' ' || a[i] == '\t')	
	    state = OUT;
	else	
	    if(state == OUT)
	    {	
		count ++;
		state = IN;
	    }
    return count;
}

/*
   统计单词个数, *b存储每个单词长度
 */
int word_num(const char a[], int *b)
{
    int i,state,count = 0;
    state = OUT;
    b[0] = 0;
    for(i = 0; a[i] != '\0'; i++)
	if(a[i] == ' ' || a[i] == '\t')	
	{
	    state = OUT;
	    b[count] = 0;
	}
	else	
	{	
	    if(state == OUT)
	    {	
		count ++;
		state = IN;
	    }
	    b[count - 1]++;
	}
    return count;
}
void sort_bubble(char *a[], int len)
{
    int i,j; 
    char *tmp;
    for(i = 1; i < len; i++)
	for(j = 0; j < len - i; j++)
	    if(strcmp(a[j],a[j+1]) > 0)
	    {
		tmp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = tmp;
	    }
}


