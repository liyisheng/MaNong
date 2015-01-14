#include<stdio.h>

/*
15: 第15题 请编写一个函数unsigned fun(unsigned w),w使一个大于10的无符号整数，
若w使n(n≥2)位的整数，则函数求出w后n－1位的数作为函数值返回。 
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
