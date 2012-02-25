/*HW 14.09.2011 Task3

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 10min
 start time 21.22
 end time 21.35
*/
#include "stdafx.h"
#include <stdlib.h>


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input m,n count of arrays(x[1]...x[m] x[m+1]...x[m+n] ), it'll be fill rand() nums: \n");
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);

	int *x = new int[m+n];
	printf("x[] = ");
	for (int i = 0; i < m+n; i++)
	{
		x[i] = rand() % 9 + 1;
		printf("%d ", x[i]);

	};

	for (int j = 0; j < m; j++)
		for (int i = m+n-1; i > 0; i--)
		{
			int t = x[i];
			x[i] = x[0];
			x[0] = t;
		};

	printf("\n Done: x[] = ");
	for (int i = 0; i  < m+n; i++)
		printf("%d ", x[i]);

	delete[] x;
	scanf("%d", &m);
	return 0;
}

