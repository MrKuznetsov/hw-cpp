/*HW 14.09.2011 Task10

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 7min
 start time 12.23
 end time 12.29
*/
#include "stdafx.h"

int sLength(char *s)
{
	int len = 0;
	for (len = 0; s[len]; len++);
	return len;
}

int _tmain(int argc, _TCHAR* argv[])
{

	char s[50];

	printf("Input string: \n");
	gets(s);
	bool foundDifference = false;
	int length = sLength(s);

	for (int i = 0; i < (length/2); i++)	
		if (s[i] != s[length-i-1])
		{
			printf("It's not palindrom");
			foundDifference = true;
			break;
		}
	if (!foundDifference)
		printf("It's palindrom");

	scanf("%d", &length);
	return 0;
}

