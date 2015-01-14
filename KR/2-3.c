#include <stdio.h>
#include <stdlib.h>
#define YES 1
#define NO 0
int htoi(char s[]){
    int hexd,i,inhex,n;
    i=0;
    if(s[i]=='0'){
	++i;
	if(s[i]=='x'||s[i]=='X')
	    ++i;
    }
    n=0;
    inhex=YES;
    while(inhex){
	if(s[i]>='0'&&s[i]<='9')
	    hexd=s[i]-'0';
	else if(s[i]>='a'&&s[i]<='f')
	    hexd=s[i]-'a'+10;
	else if(s[i]>='A'&&s[i]<='F')
	    hexd=s[i]-'A'+10;
	else
	    inhex=NO;
	if(inhex==YES)
	    n=16*n+hexd;
	i++;
    }
    return n;
}
int main(){
    int count=10;
    int i;
    char s[100];
    for(i=0;i<10;i++){
	int num=rand()%10000;
	int n;
	sprintf(s,"%#x",num);
	n=htoi(s);                                     
	printf("%#x %s %d %d \n",num,s,num,n);

    }

}
