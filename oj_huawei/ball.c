#include<stdio.h>
/*
假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？
*/
double get_length(int high, int time);
double total_journey(int high, int time)
{
    int i = 1;
    double total = 1.0*high;
    for(; i < time; i++)
    {
	total += 2*get_length(high, i);	
    }
    return total;
}


double get_length(int high, int time)
{
    int i;
    double length = high;
    for(i = 0; i < time; i++)
	length /= 2;
    return length;
}

int main()
{
    int high;
    scanf("%d", &high);
    printf("%lf", total_journey(high, 5));
    printf("%lf", get_length(high, 5));

}
