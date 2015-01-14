#include<stdio.h>
int f1()
{
    return 0;
}


int main()
{
    int (*f)();
    printf("%lu\n", sizeof(f1));
    printf("%lu\n", sizeof(*f1));
    printf("%lu\n", sizeof(&f1));
    printf("%lu\n", sizeof(f));
    
    char *a;
    printf("%lu\n",sizeof(a));
}
