/*************************************************************************
  > File Name: 2.11_2_INItoXML.c
  > Author: liyisheng
  > Mail: liyishengchn@gmail.com 
  > Created Time: Mon 26 Jan 2015 02:36:32 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int INItoXML(char *a, char *b);
int main()
{

	char a[100] = "aaaa";
	char b[100] = "2.txt";
	INItoXML(a, b);
	return 0;
}
int INItoXML(char *a, char *b)
{

	FILE *fp = fopen(a, "r");
	FILE *fp_x = fopen(b, "w");
	char buf[100];
	char section[100];
	char key[100];
	char value[100];
	int i;
	while(1)
	{

		memset(buf, 0, sizeof(buf));
		if(fgets(buf, 100, fp) == NULL)
			break;
		if(strlen(buf) == 0)
			continue;
		if(*buf == ';')
		{
			buf[strlen(buf) - 1] = '\0';
			fprintf(fp_x, "<!-- %s -->\n", buf + 1);
		}
		else if(buf[0] == '[')
		{
			memset(section, 0, sizeof(section));
			memcpy(section, buf + 1, strlen(buf) - 3);
			fprintf(fp_x, "<%s>\n", section);
			while(1)
			{
				memset(buf, 0, sizeof(buf));
				fgets(buf, 100, fp);
				if(strlen(buf) == 0 || buf[0] == '\n')
					break;
				i = 0;
				while(buf[i] != ' ' && buf[i] != '=')
				{
					key[i] = buf[i];                                                        
					i++;
				}
				key[i] = '\0';
				while(!isalpha(buf[i]))
					i++;
				strcpy(value, buf + i);
				value[strlen(value) - 1] = '\0';
				fprintf(fp_x, "\t<%s>%s</%s>\n", key, value, key);
				printf("\t<%s>%s</%s>\n", key, value, key);
			}
			fprintf(fp_x, "<%s>", section);
		}

	}
}
