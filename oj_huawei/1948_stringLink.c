#include<stdio.h> 
#include<string.h> 
#define N 100 
#define M 100
int wd_extract(const char *s,char (*b)[M], int *wd_len);
int main()
{
    char a[100];
    char s[N][M];
    int c;
    int i,j,k,l,max,max_l,wd_num,wd_len;
    max =  max_l = 0;
    while(gets(a))
    {
	wd_num = wd_extract(a, s, &wd_len);
	for(i = 0; i < wd_num; i++)
	{
	    for(j = 0; j < wd_num; j++)
	    {
		if(j == i) continue;
		for(l = 0,k = strlen(s[i]) - wd_len + 1;(k < strlen(s[i])) && (s[i][k] == s[j][l]); k++,l++);
		if(k == strlen(s[i]))
		{
		    s[i][k] = s[j][l];
		    s[i][k + 1] = '\0';
		}
	    }
	}

	for(i = 0; i < wd_num; i++)
	{
	    if(max < strlen(s[i])) 
	    {
		max = strlen(s[i]);
		max_l = i;
	    }
	}
	printf("%s\n",s[max_l]);
    }
    return 0;
}



int wd_extract(const char *s,char (*b)[M], int *wd_len)
{
    int i,j,count = 0;
    int state = 0;
    for(i = 0; s[i]!= '\0'; i++)
    {
	if(s[i] == ' ')
	{
	    if(state == 1)
	    {
		b[count - 1][j] = '\0';
		*wd_len = j;
	    }
	    state = 0;
	}else
	{
	    if(state == 0)
	    {
		state = 1;
		count++;
		j = 0;
	    }
	    b[count - 1][j++] = s[i];    
	}
    }	
    return count;
}

