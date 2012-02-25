/*HW 21.09.2011 Task1

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 5min
 start time 14.57
 end time 15.02
*/
#include "stdafx.h"

int getFibonaccilRecursive(int n)
{
	if (n < 2)
		return 1;
	return (getFibonaccilRecursive(n - 2) + getFibonaccilRecursive(n - 1));
}

int getFibonaccilIterative(int n)
{
	int res = 1;
	int t = 1;
	while ( --n > 0)
	{
		int tmp = res;
		res += t;
		t = tmp;
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input a: \n");
	int a = 0;
	scanf("%d", &a);
	printf("Recursively : %d \n", getFibonaccilRecursive(a));
	printf("Iteratively: %d", getFibonaccilIterative(a));

	scanf("%d", &a);
	return 0;
}

