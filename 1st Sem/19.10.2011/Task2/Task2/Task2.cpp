/*HW 19.10.2011 Task2

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 40min
 start time 16.20
 end time 17.13
*/
#include "stdafx.h"
#include <stdlib.h>
#include <string>

int binarToDecimal(char *c, int count)
{
	int res = 0;
	int pow = 1;
	for (int i = count - 1; i > -1; i--)
	{
		res += pow * c[i];
		pow *= 2;
	}
	return res;
};

int getMantCount(char *c, int count)
{
	int res = count;
	while (!c[res-1])
		res--;
	return res;
}

void printMant(char *c, int count)
{
	unsigned __int64 mant = 0;
	unsigned __int64 d = 1;
	count = getMantCount(c, count);

	for (int i = 0; i < count; i++)
	{
		if (i < 19) // точность выода
		{
			mant *= 10;
			d *= 5;
		}
		else
			d /= 2;

		if (c[i])
			mant += d;
	}
	printf("1.%llu", mant);
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input double\n");
	double a = 0;
	scanf("%lf", &a);
	const int count = sizeof(double) * 8;
	

	char byteNumber[count];

	unsigned __int64 mask = 1;
	unsigned __int64 *b = (unsigned __int64 *)(&a);


	for (int i = 0; i < count; i++)
	{
		byteNumber[count - i - 1] = (mask & *b) ? 1 : 0;
		mask = mask << 1;
	}; 

	printf("bits = ");
	for (int i = 0; i < count; i++)
		printf("%d", byteNumber[i]);
	putchar('\n');

	if (byteNumber[0] == 1)
		putchar('-');
	int pow = binarToDecimal(&byteNumber[1] ,11);

	printMant(&byteNumber[12], count - 12);

	printf("*2^(%d)", pow - 1023);

	
	scanf("%*s");
	return 0;
}

