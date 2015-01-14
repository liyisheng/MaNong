#include<stdio.h>  
#include<string.h>  
char *reverse(char *a);  
int main()  
{  
    char a[100];  
    gets(a);  
    puts(reverse(a));  

}  

char *reverse(char *a)  
{  
    int i,j,temp;  
    for(i = 0, j = strlen(a)-1; i < j; i++,j--)  
	temp = a[i], a[i] = a[j], a[j] = temp;  
    return a;  
}  
