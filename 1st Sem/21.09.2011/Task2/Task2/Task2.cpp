/*HW 21.09.2011 Task9

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 6min
 start time 15.17
 end time 15.25
*/
#include "stdafx.h"

int pow(int a, int b)
{
	float res = 1;
	while(b > 0)
	{
		if (b % 2 == 1)
			res *= a;
		b /= 2;
		a *= a;
	}
	return res;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input a: \n");
	int a = 0, b = 0;
	scanf("%d", &a);
	printf("Input b: \n");
	scanf("%d", &b);
	printf("a^b = %d \n", pow(a, b));

	scanf("%d", &a);
	return 0;
}

