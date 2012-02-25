/*HW 19.10.2011 Task1

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 20min
 start time 15.13
 end time 15.30
*/
#include "stdafx.h"
#include <stdlib.h>
#include <string>

int getCharCode(char c) //«аглавные и строчные считаютс€ одинаковыми
{
	if (c < 'a')
		return c - 'A';
	return c - 'a';
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input string\n");
	char s[100];
	fgets(s, 100, stdin);
	
	int i = 0;

	bool chars[28]; //кол-во букв англ алфавита
	memset(chars, 0, 28);

	while (s[i])
	{
		if (s[i] == ' ')
		{
			printf(" ");
			memset(chars, 0, 28);
			i++;
			continue;
		}

		int code = getCharCode(s[i]);
		if (!chars[code])
			printf("%c", s[i]);
		chars[code] = true;

		i++;
	}


	scanf("%*s");
	return 0;
}

