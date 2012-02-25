/*HW 26.10.2011 Task2

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 30min
 start time 20.12
 end time 20.45
*/
#include "stdafx.h"
#include <stdlib.h>
#include "tree.h"

bool isOperation(char c)
{
	return (c == '+' || c== '-' || c == '/' || c == '*');
}
int getNum(char c)
{
	return c - '0';
}

Tree *parseSample(char *s, int &index)
{
	Tree *tmp;
	if (s[index] == '(')
	{
		tmp = parseSample(s, ++index);
		index++; // miss ')'
		return tmp;
	}
	else if (isOperation(s[index]))
	{
		tmp = new Tree(s[index]);
		index++;
		Tree *left = parseSample(s, index);
		Tree *right = parseSample(s, index);
		tmp->leftNode = left;
		tmp->rightNode = right;
		return tmp;
	} else // ×ÈÑËÎ
	{
		tmp = new Tree(s[index]);
		index++;
		return tmp;
	}
};

int runSample(Tree *t)
{
	if (isOperation(t->value))
	{
		char op = t->value;
		int l = runSample(t->leftNode);
		int r = runSample(t->rightNode);
		switch (op)
		{
			case '+': return l + r;
			case '-': return l - r;
			case '*': return l * r;
			case '/': return l / r;
		}
	} else 
		return getNum(t->value);

};

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input sample\n");
	char c[100];
	gets(c);

	int index = 0;
	Tree *t = parseSample(c, index);

	printf("%s = %d", c, runSample(t));

	deleteTree(t);

	scanf("%*s");
	return 0;
}

