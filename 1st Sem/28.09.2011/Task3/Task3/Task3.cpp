/*HW 28.09.2011 Task3

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 90min
 start time 21.34
 end time 22.15
*/
#include "stdafx.h"

#define MAXCHAR 50

/*
  (2 + 3 + 5) / (2 - 1) = 23+5+21-/

*/
void level1(char *c, int &index);
void level2(char *c, int &index);


void level0(char *c, int &index) // + -
{
	if (!c[index]) return;
	level1(c, index);
	while ( c[index] == '+' || c[index] == '-')
	{
		int i = index++;
		level1(c, index);
		printf("%c", c[i]);
		if (!c[index]) return;
	}
}

void level1(char *c, int &index)// * /
{
	if (!c[index]) return;
	level2(c, index);
	while ( c[index] == '*' || c[index] == '/')
	{
        int i = index++;
		level2(c, index);
		printf("%c", c[i]);
		if (!c[index]) return;
	}
}

void level2(char *c, int &index)// ( )
{
	if (!c[index]) return;
	if ( c[index] == '(')
	{
		index++;
		level0(c, index);
		if (!c[index]) return;
	}
	else
	if ( c[index] != ')')
		printf("%c", c[index]);
	index++;
}

void deleteSpaces(char *c)
{
	char tmp[MAXCHAR];
	int i = 0, j = 0;

	while(c[i])
	{
		if (c[i] != ' ')
		{
			c[j] = c[i];
			j++;
		}
		i++;
	}
	c[j] = 0;

}

void infixToPostfix(char *c)
{
	deleteSpaces(c);
	int i = 0;
	level0(c, i);
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input expression: \n");

	char c[MAXCHAR];
	fgets(c, MAXCHAR, stdin);
	
	infixToPostfix(c);

	scanf("%*s");
	return 0;
}

