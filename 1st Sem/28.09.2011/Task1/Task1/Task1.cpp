/*HW 28.09.2011 Task1

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 3min
 start time 14.49
 end time 14.55
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
		while (a[i] > pointer)
			i++;
		while (a[j] < pointer)
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

	bool done = false;
	int max = 0;
	for (int i = 1; i < count; i++)
		if (a[i] == a[i-1])
		{
			max = a[i];
			done = true;
			break;
		};
	if (done)
		printf("\nMax elements of array is %d", max);
	else
		printf("\nThere are no max elements");

	delete[] a;

	scanf("%*s");
	return 0;
}

