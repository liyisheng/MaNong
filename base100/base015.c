#include<stdio.h>

/*
15: ��15�� ���дһ������unsigned fun(unsigned w),wʹһ������10���޷���������
��wʹn(n��2)λ���������������w��n��1λ������Ϊ����ֵ���ء� 
*/


unsigned fun(unsigned w)
{   
    unsigned n = 0; 
    unsigned base = 1;
    
    while(w > 10)
    {
	n += base*(w%10);		
	base *= 10;
	w /= 10;
    } 
    return n;
}


int main()
{
    unsigned w = 87687198;    
    fun(w); 
    printf("%d\n", fun(w));

    return 0;
}
