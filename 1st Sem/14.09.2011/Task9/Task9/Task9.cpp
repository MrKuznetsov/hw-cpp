/*HW 14.09.2011 Task9

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 7min
 start time 12.15
 end time 12.20
*/
#include "stdafx.h"

float pow(int a, int b)
{
	float res = 1;
	if (b > 0)
		for (int i = 0; i < b; i++)
			res *= a;
	else if (b < 0)
		for (int i = 0; i < -b; i++)
			res /= a;
	return res;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input a: \n");
	int a, b;
	scanf("%d", &a);
	printf("Input b: \n");
	scanf("%d", &b);
	printf("a^b = %f \n", pow(a, b));

	scanf("%d", &a);
	return 0;
}

