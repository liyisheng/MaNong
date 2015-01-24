#include<stdio.h>
int main()
{
    int a,b,c,d;
    int r = scanf("%d.%d.%d.%d", &a,&b,&c,&d);
    if(r != 4)
	printf("NO\n");
    if(isIP(a) && isIP(b) && isIP(c) && isIP(d))
	printf("YES\n");
    else 
	printf("NO\n");

}
int isIP(int a)
{
    return a >= 0 && a <= 255;
}
