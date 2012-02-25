/*HW 16.11.2011 Task11

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 5min
 start time 17.15
 end time 17.20
*/
#include "stdafx.h"
#include <stdlib.h>
#include "bubble.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input count of array(x[count]), it'll be fill rand() % 20 nums: \n");
	int count = 0;
	scanf("%d", &count);

	int *a = new int[count];
	printf("a[] = ");
	for (int i = 0; i < count; i++)
	{
		a[i] = rand() % 20 + 1;
		printf("%d ", a[i]);
	};

	bsort(a, count);

	printf("\nDone: a[] = ");
	for (int i = 0; i < count; i++)
		printf("%d ", a[i]);

	delete[] a;
	scanf("%d", &count);
	return 0;
}

