/*HW 21.09.2011 Task9

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 30min
 start time 15.41
 end time 16.15
*/
#include "stdafx.h"
#include "stdlib.h"

/*
   9
  / \
 7   6
/ \
4 3

[9 7 6 4 3]
*/

void HeapDown(int *a, int count, int index)
{
	int max = index;
	while (true)
	{
		int child = index * 2 + 1;
		if (child < count && a[child] > a[max])
			max = child;
		child++;
		if (child < count && a[child] > a[max])
			max = child;

		if ( max == index)
			break;
		int tmp = a[max];
		a[max] = a[index];
		a[index] = tmp;

		index = max;
	}
}

void HeapSort(int *a, const int count)
{
	for (int i = count / 2 - 1; i >= 0; i--)
		HeapDown(a, count, i);

	int j = count;
	while ( --j>0)
	{
		int tmp = a[0];
		a[0] = a[j];
		a[j] = tmp;
		HeapDown(a, j, 0);

	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input count of array(a[count]), it'll be fill rand() % 20 nums: \n");
	int count = 0;
	scanf("%d", &count);

	int *a = new int[count];
	printf("a[] = ");
	for (int i = 0; i < count; i++)
	{
		a[i] = rand() % 20 + 1;
		printf("%d ", a[i]);
	};

	HeapSort(a, count);

	printf("\nDone: a[] = ");
	for (int i = 0; i < count; i++)
		printf("%d ", a[i]);

	delete[] a;
	scanf("%d", &count);
	return 0;
}

