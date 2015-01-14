#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*

*/


int main()
{

    char c[3][20] = {"ajojafb","aoafoba","aojoabaoqo"};
    char (*a)[20] = c;

    char *b[] = {"ajojafb","aoafoba","aojoabaoqo"};
    
    printf("%s\n",c[0]);
    printf("%s\n",*(a+1));
    printf("%s\n",*(b+1));
    
    return 0;
}
