/*************************************************************************
  > File Name: ModifyString.cc
  > Author: liyisheng
  > Mail: liyishengchn@gmail.com 
  > Created Time: Mon 13 Apr 2015 06:03:51 AM PDT
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
int FindSubString( char* pch )
{

	int   count  = 0;
	char  * p1   = pch;
	while ( *p1 != '\0' )
	{

		if ( *p1 == p1[1] - 1 )
		{

			p1++;
			count++;
		}else  {

			break;
		}
	}
	int count2 = count;
	while ( *p1 != '\0' )
	{

		if ( *p1 == p1[1] + 1 )
		{

			p1++;
			count2--;
		}else  {

			break;
		}
	}
	if ( count2 == 0 )
		return(count);
	return(0);
}
void ModifyString( char* pText )
{

	char  * p1   = pText;
	char  * p2   = p1;
	while ( *p1 != '\0' )
	{

		int count = FindSubString( p1 );
		if ( count > 0 )
		{

			*p2++ = *p1;
			sprintf( p2, "%i", count );
			cout << p1 << endl;
			cout << *(p1+2) << endl;
			while ( *p2 != '\0' )
			{

				p2++;
			}
			p1 += count + count + 1;
			cout  << p1 << endl;
		}else  {

			*p2++ = *p1++;
		}
	}
}
int main( void )
{

	char text[32] = "XYBCDCBABABA";
	ModifyString( text );
	cout << text << endl;
}
