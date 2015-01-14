#include<stdio.h>
#include<ctype.h>


void fun1();
void fun2();
void fun3();
int main()
{
    int c; 
    void (*fun)(void);

    while((c = getchar()) != EOF)
    {
	if(isalpha(c))
	    fun = fun1;
	else if(isdigit(c))
	    fun = fun2;
	else
	    fun = fun3;
	fun();
    }
    return 0;
}





void fun1()
{
    putchar(7);
}

void fun2()
{
    putchar(35);  
}
void fun3()
{
    putchar(40);
}
