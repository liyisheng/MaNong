#include<stdio.h>
#include<stdlib.h>

/*
26: ��26�� ���дһ������fun�����Ĺ����ǣ��������¹�ʽ��x��ֵ(Ҫ�����㾫��0.0005����ĳ��С��0.0005ʱֹͣ����)��
x/2=1+1/3+1��2/3��5+1��2��3/3��5��7+1��2��3��4/3��5��7��9+��+1��2��3������n/3��5��7��(2n+1)
�������к�������뾫��0.0005����������Ϊ3.14���� 
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
