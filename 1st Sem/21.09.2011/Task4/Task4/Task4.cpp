/*HW 21.09.2011 Task4

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 5min
 start time 16.40
 end time 16.53
*/
#include "stdafx.h"
int NOD(int a, int b) //наибольший общий делитель
{
	return (a == 0 ? b : NOD(b % a, a));
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input N: \n");
	int N = 0;
	scanf("%d", &N);

	for (int i = 2; i < N; i++)
		for (int j = 1; j < i; j++)
			if (NOD(j, i) == 1)
				printf("%d / %d\n", j, i);

	scanf("%d", &N);
	return 0;
}

