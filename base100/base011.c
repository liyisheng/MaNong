#include<stdio.h>

/*
第11题 下列程序定义了n×n的二维数组，并在主函数中自动赋值
请编写函数 fun(int a[][n]),该函数的功能是：使数组左下半三角元素中的值全部置成0。 
*/
int main()
{
    int a[4][4]; 
    int i,j;
    for(i = 0; i < 4; i++)
	for(j = 0; j < 4 ; j++)
	    a[i][j] = i*j;
    
    fun(a);
    for(i = 0; i < 4; i++)
    {
	for(j = 0; j < 4 ; j++)
	    printf("%d ", a[i][j]);
	printf("\n");
    }
    return 0;
}


int fun(int a[][4])
{
    int i,j; 
    for(i = 0; i < 4; i++)
    {
	for(j = 0; j < i; j++ )
	{
	    a[i][j] = 0;
	}
    }
    return 0;
}
