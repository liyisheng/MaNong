#include<stdio.h>

/*
16: ��16�� ���дһ������float fun(double h),�����Ĺ���ʹ�Ա���h�е�ֵ����2λС����
���Ե���λ������������(�涨h�е�ֵλ����)�� 
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
