/*HW 14.09.2011 Task5

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 6min
 start time 9.05
 end time 9.15
*/
#include "stdafx.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input string[50]: \n");
	char s[50];
	std::cin.getline(s, 50);

	char *p = s;
	int i = 0;
	while (*p)
	{
		if (*p == '(')
			i++;
		if (*p == ')')
			i--;
		if (i == -1)
		{
			printf("\n Error, too much ')'");
			break;
		}
		p++;
	};

	if (i > 0) 
		printf("\n Error!!");
	else if (i == 0)
		printf("\n It's fine!!");

	int x;
	scanf("%d", &x);
	return 0;
}

