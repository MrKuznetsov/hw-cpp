/*HW 05.10.2011 Task2

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 20min
 start time 15.22
 end time 14.46
*/
#include "stdafx.h"
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input odd N, NxN - count of array\n");
	int N = 0;
	scanf("%d", &N);

	int *a = new int[N*N];

	for(int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			a[y * N + x] = rand() % 10;
			printf("%d ", a[y * N + x]);
		}
		printf("\n");
	}
	printf("\n");
	/*
         _________
	     |  ____  | |
	     | |    | | |
         | | || | | |
		 | | |__| |	|
		 | |______| |
		 |__________|
	*/
	int x = N / 2;
	int y = N / 2;

	int step = 1;
	int dir = 1;
	while(true)
	{
        for(int i = 0; i < step; i++) 
        {
			printf("%d ", a[y * N + x]);
			y -= dir;
		}
		if ( y == -1)
			break;
		for(int i = 0; i < step; i++) 
		{
			printf("%d ", a[y * N + x]);
			x -= dir;
		}
		step++; 
		dir = -dir;
	}

	delete[] a;

	scanf("%*s");
	return 0;
}

