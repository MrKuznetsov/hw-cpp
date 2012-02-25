/*HW 14.09.2011 Task11

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 13min
 start time 18.47
 end time 19.07
*/
#include "stdafx.h"
#include <stdlib.h>

void qsort(int* a, int begin, int end)
{
	int pointer = a[begin + (end - begin) / 2];
	int i = begin;
	int j = end;
	do
	{
		while (a[i] < pointer)
			i++;
		while (a[j] > pointer)
			j--;
		if (i <= j)
		{
			int t  = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	while (i <= j);
	if ( begin < j)
		qsort(a, begin, j);
	if ( end > i)
		qsort(a, i, end);
}


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

	qsort(a, 0, count-1);

	printf("\nDone: a[] = ");
	for (int i = 0; i < count; i++)
		printf("%d ", a[i]);

	delete[] a;
	scanf("%d", &count);
	return 0;
}

