#include "stdafx.h"
#include "bubble.h"

void bsort(int* a, int count)
{
	bool tmp = true;
	while (tmp)
	{
		tmp = false;
		for (int i = 0; i < count - 1; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				tmp = true;
			}
	}
}

void swap(int &a, int &b)
{ 
	int tmp = a;
	a = b;
	b = tmp;
}