#include<stdio.h>
int LCM(int a, int b)
{
    int min = a < b? a: b;
    int max = a > b? a: b;
    int i = min;
    
    while(i%max)
	i += min;
    return i;
}
int main()
{
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    printf("%d\n",LCM(n1,n2));
    return 0;
}


