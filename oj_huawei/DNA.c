#include<stdio.h>
#include<string.h>
int GC_Ratio(char *str, char *b, int len)
{
    int i,j;
    int str_len = strlen(str);
    int count = 0;
    double gc_ratio;
    double gc_ratio_max = 0.0;
    int max_index, min_index;
    for(i = 0; i < str_len - len; i++)
    {
	count = 0;
	if(str[i] != 'G' && str[i] != 'C')
	    continue;
	for(j = 0; j < str_len; j++)
	{
	    if(str[i + j] == 'G' || str[i + j] == 'C')
		count++;
	    if(j >= len - 1)
	    {
		gc_ratio = (1.0)*count/(j + 1);	
		if(gc_ratio > gc_ratio_max)
		{
		    gc_ratio_max = gc_ratio;
		    min_index = i;
		    max_index = i + j; 
		}
	    }
	}
    }
    memcpy(b, &str[min_index], max_index - min_index + 1);
    b[max_index - min_index + 1] = '\0';

}

int main()
{
    char s[100];
    char b[100];
    int len;
    scanf("%s",s);
    scanf("%d", &len);

    GC_Ratio(s, b, len);
    printf("%s\n",b);
}

