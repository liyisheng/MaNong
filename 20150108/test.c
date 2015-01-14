#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern void get_a_day(const char **);

static const char *msg[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};


void get_a_day(const char **pp)
{
    static int i = 0;
    *pp = msg[i%7];
    i++;
}

char *get_a_day1(int idx)
{
    static  char buf[10];
    strcpy(buf, msg[idx]);
    return buf;
}

int main()
{
    const char *firstday = NULL;
    const char *secondday = NULL;
    get_a_day(&firstday);
    get_a_day(&secondday);
    printf("%s\t%s\n", firstday, secondday);

    char *a = get_a_day1(0);
    char *b = get_a_day1(1);

    printf("%s\t%s\n",a,b);


    return 0;
}

