#include<stdio.h>
#include<stdlib.h>

/*
26: 第26题 请编写一个函数fun，它的功能是：根据以下公式求x的值(要求满足精度0.0005，即某项小于0.0005时停止迭代)：
x/2=1+1/3+1×2/3×5+1×2×3/3×5×7+1×2×3×4/3×5×7×9+…+1×2×3×…×n/3×5×7×(2n+1)
程序运行后，如果输入精度0.0005，则程序输出为3.14…。 
*/


double fun(double d)
{
    double temp = 1.0;
    double s = 0;
    double pi = 0;
    int n = 1;
    while(temp >= d)
    {
	pi += temp;	
	s = (1.0*n)/(2*n + 1);	
	temp *= s;
	n++;
    }
    pi *= 2;
    return pi;
}

int main()
{
    printf("%f\n", fun(0.0005));
    return 0;
}
