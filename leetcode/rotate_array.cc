/*************************************************************************
    > File Name: rotate_array.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 07 Apr 2015 06:38:09 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
/*
void rotate(int nums[], int n, int k){


	int time = k%n;
	if(time==0) return;
	int *temp = new int[time];
	memcpy(temp, nums + n - time, sizeof(int) * time);
	for(int i = n - 1; i >= time; --i)
	{
		int last = nums[i];
		nums[i] = nums[i - time];
	}
	for(int i = 0; i < time; ++i)
		nums[i] = temp[i];
}
*/
void reverse(int nums[], int n)
{
	for(int i = 0; i < n/2; ++i)
	{
		int temp = nums[i];
		nums[i] = nums[n - 1 - i];
		nums[n -1 - i] = temp;
	}
}
void rotate(int nums[], int n, int k)
{
	int time = k%n;
	reverse(nums, n - time);	
	reverse(nums + n - time, time);
	reverse(nums, n);
}
int main(int argc, char *argv[])
{

	int a[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	//int a[3] = {1, 2, 3};
	rotate(a, 13, 17);
	for(int i = 0 ; i < 13; ++i)
		cout << a[i] << " ";
	return 0;
}
