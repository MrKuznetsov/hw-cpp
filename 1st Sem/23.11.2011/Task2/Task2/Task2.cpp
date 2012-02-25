/*HW 23.11.2011 Task2

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 30min
 start time 20.43
 end time 21.14
*/

#include "stdafx.h"
#include "rksearch.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char s[100];
	char ps[10];

	printf("Input string[100]:\n");
	gets(s);
	printf("Input substring[10]:\n");
	gets(ps);

	printf("substring in string in pos:\n");
	strFind(s,ps);

	scanf("%*s");
	return 0;
}

