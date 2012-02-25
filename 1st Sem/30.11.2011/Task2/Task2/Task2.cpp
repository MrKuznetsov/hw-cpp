/*HW 30.11.2011 Task2

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 40min
 start time 15.45
 end time 16.09
*/
#include "stdafx.h"

bool isDig(char c)
{
	return (c <= '9' && c >= '0');
}

bool isFloat(char *p)
{
	int state = -1;
	char *c = p;

	if (isDig(*c))
		state = 0;
	else if (*c == '-')
		state = 10;
	else
		return false;
	c++;
	while (true)
	{
		switch (state)
		{
		    case 10:
				if (isDig(*c))
				{
					c++;
					state = 0;
				}
				else
					state = -1;
				break;
/* 0 */    	case 0: 
				if (isDig(*c))
					c++;
				else if (*c == '.')
				{
					state = 1;
					c++;
				} else if (*c == 'e')
				{
					state = 3;
					c++;
				} else if (*c == 0)
					return true;
				else
					state = -1;
				break;
/* 1 */		case 1:
				if (*c == 0)
					state = -1;
				else if (isDig(*c))
				{
					state = 2;
					c++;
				} else
					state = -1;
				break;
/* 2 */		case 2:
				if (*c == 0)
					return true;
				else if (isDig(*c))
					c++;
				else if (*c == 'e')
				{
					state = 3;
					c++;
				} else
					state = -1;
				break;
/* 3 */	    case 3:
				if (*c == 0)
					state = -1;
				else if (*c == '+' || *c == '-')
				{
					state = 4;
					c++;
				} else if (isDig(*c))
				{
					state = 5;
					c++;
				} else
					state = -1;
				break;
/* 4 */	  	case 4:
				if (*c == 0)
					state = -1;
				else if (isDig(*c))
				{
					state = 5;
					c++;
				} else 
					state = -1;
				break;
/* 5 */	  	case 5:
				if (*c == 0)
					return true;
				else if (isDig(*c))
					c++;
				else 
					state = -1;
				break;
/* -1 */  	case -1:
				return false;
		}
	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input string\n");
	char s[100];
	scanf("%s", s);

	printf("%s", isFloat(s) ? "true" : "false");

	scanf("%*s");
	return 0;
}

