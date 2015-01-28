#include<stdio.h>
#include<stdlib.h>


int main()
{
    FILE *fp;
    char *file_name = "/home/lys/manong/test.c";
    char TEMP[1024];
    fp = fopen(file_name, "r");
    while(fgets(TEMP, 1024, fp) != NULL)    
    {
	printf("%s", TEMP);
    }

}
