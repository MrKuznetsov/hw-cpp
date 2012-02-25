/*HW 21.09.2011 Task3

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 50min
 start time 17.24
 end time 18.23
*/
#include "stdafx.h"


void printArr(int *a, int count)
{
	printf("%d", a[0]);
	for (int i = 1; i < count; i++)
		printf(" + %d", a[i]);
	printf("\n");
}
void decomposition(int num, int level = 0) 
{
	static int sum[40];
	
	if (num == 1)  // 1
	{
		sum[level] = 1;
		printArr(sum, level+1);
		return;
	}
/*	if (num == 2) // 1+1
	{
		sum[level] = 1;
		sum[level+1] = 1;
		printArr(sum, level+2);
		return;

	} */
	for (int i = num - 1; i > 0; i--)
	{
		if (i > sum[level-1] && level != 0)  //не даем повторение сумм
			i = sum[level-1];
		sum[level] = i;
		int difference = num - i;
		if ( i >= difference && difference > 1) 
		{
			sum[level+1] = difference;
			printArr(sum, level+2);
		}
		decomposition(difference, level+1);
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input N: \n");
	int N = 0;
	scanf("%d", &N);

	decomposition(N);

	scanf("%d", &N);
	return 0;
}

