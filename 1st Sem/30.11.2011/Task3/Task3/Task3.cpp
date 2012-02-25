/*HW 07.12.2011 Task1

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 30min
 start time 16.20
 end time 17.21
*/
#include "stdafx.h"
#include "parser.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("input sample\n");
	char s[100];
	gets(s);

	printf("%s", parse(s) ? "true": "false");

	scanf("%*s");

	return 0;
}

