/*************************************************************************
    > File Name: loadStuChartFile.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 26 Jan 2015 07:41:01 PM CST
 ************************************************************************/

#include<func.h>

int loadStuChartFile(char *file, CrossLink *l)
{
	int row, col;
	char name[NAME_SIZE];
	char buf[512];
	FILE *fp = fopen(file, "rb");	
	while(memset(buf,0,sizeof(buf)),fgets(buf, 512, fp) != NULL)
	{
		memset(name, 0, sizeof(name));
		getValueByDelim(buf, name, ",");			
		row = *buf - '0';
		col = *(buf + 2) - '0';
		InsertCrossList(l, row, col, name);
	}
	fclose(fp);
}

int getValueByDelim(char *sSrc, char *sDest, char *sDelim)
{
	char *sEnd;
	if( *sSrc == '\0')
		return 1;
	sEnd = strstr(sSrc, sDelim);
	if(sEnd == NULL)
		return 2;
	memcpy(sDest, sSrc,sEnd-sSrc);
	strcpy(sSrc, sEnd + strlen(sDelim));
	return 0;
}
