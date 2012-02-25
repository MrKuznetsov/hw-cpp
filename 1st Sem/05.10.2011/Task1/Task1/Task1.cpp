/*HW 05.10.2011 Task1

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 10min
 start time 14.51
 end time 14.59
*/
#include "stdafx.h"
#include <stdlib.h>
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input first string\n");
	char s1[50];
	gets(s1);

	printf("Input second string\n");
	char s2[50];
	gets(s2);

	int chars[255]; //Все символы
	memset(chars, 0, 255); 

	for (int i = 0; s1[i]; i++)
		chars[s1[i]]++;

	for (int i = 0; s2[i]; i++)
		chars[s2[i]]--;

	printf("Is it possible to get second string from first? ");

	bool isMismatch = false;
	for (int i = 0; s1[i]; i++)
		if (chars[s1[i]] > 0)
		{
			printf("NO");
			isMismatch = true;
		    break;
		};
	if (!isMismatch)
		printf("YES");

	scanf("%*s");
	return 0;
}

