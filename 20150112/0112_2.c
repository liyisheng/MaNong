#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
将包含字符数字的字符串分开 ,使得 分开后的字符串前一部是数字，后一部分是字母。例如 “h1ell2o3” ->"123hello"
*/


char *depart(char *src)
{
    int i,j = 0;
    int k = 0;
    int count_num = 0; 
    int length = strlen(src);
    char *temp = (char *)malloc(length *sizeof(char) + 1);
    strcpy(temp,src);
//    printf("%s\n",temp);
    for(i = 0; temp[i] != '\0'; i++)
	if(temp[i] >= '0' && temp[i] <='9')
	    count_num++;
//    printf("%d\n", count_num);
    for(i = 0; temp[i] != '\0'; i++)
    {
	if(temp[i] >= '0' && temp[i] <='9')
	{
	    src[j] = temp[i];  
	    j++;
	}else
	{
	    src[count_num + k] = temp[i];
	    k++;
	}
    }
    src[i] = '\0';
    free(temp);
    return src;
}

int main()
{
    char a[8] = "h1ell2o3";

    printf("%s\n",depart(a));
    return 0;
}
