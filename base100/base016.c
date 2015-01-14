#include<stdio.h>

/*
16: 第16题 请编写一个函数float fun(double h),函数的功能使对变量h中的值保留2位小树，
并对第三位进行四舍五入(规定h中的值位正数)。 
*/


double fun(double h)
{
    long t;
    double s;
    h=h*1000;
    t=(h+5)/10;
    s=(double)t/100.0;
    return s;  
}

int main()
{
    double n = 172.8791; 
    printf("%f\n", fun(n));
    return 0;
}
