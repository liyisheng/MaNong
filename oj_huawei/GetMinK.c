#include<stdio.h>
#include<stdlib.h>


int GetMinK(unsigned uiInputNum, int *pInputArray, unsigned uiK, int *pOutputArray);

int GetMinK(unsigned uiInputNum, int *pInputArray, unsigned uiK, int *pOutputArray)
{
    int i, j, temp;    
    if(uiK > uiInputNum)
	return 0;
    for(i = 0; i < uiK; i++)
    {
	for(j = uiInputNum - 1; j > i;j--)	
	    if(pInputArray[j] < pInputArray[j - 1]) 
		temp = pInputArray[j], pInputArray[j] = pInputArray[j - 1], pInputArray[j-1] = temp;

    }
    for(i = 0; i < uiK; i++)
	pOutputArray[i] = pInputArray[i];
    return 1;
}

int main()
{
    int i = 0;
    int num, k;
    int *input;
    int *output;
    scanf("%d%d", &num, &k);
    input = (int *)calloc(num, sizeof(int));
    output = (int *)calloc(k, sizeof(int));
    while(i < num)  
    {
	scanf("%d", &input[i++]);
    }
    GetMinK(num, input, k, output);

    for(i = 0; i < k; i++)
	printf("%d ",output[i]);
    printf("\n");
    free(input);
    free(output);
}
