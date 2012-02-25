/*HW 16.11.2011 Task2

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 90min
 start time 20.12
 end time 21.59
*/
#include "stdafx.h"
#include "graph.h"
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Reading from file...:\n");

	FILE * fd = fopen("FILE.TXT", "r"); 

	int n = 0, m = 0;// города и дороги
	fscanf(fd, "%d %d", &n, &m);

	Graph *g = new Graph(n);

	for (int k = 0; k < m; k++)
	{
		int i = 0, j = 0;
		int len = 0;
		fscanf(fd, "%d %d %d", &i, &j, &len);
		g->setM(i - 1, j - 1) = len;
		g->setM(j - 1, i - 1) = len;
	}

	fclose(fd);

	bool *flags = new bool[n];
	memset(flags, 0, n);

	int city = 0; //начинаем с 1ого города
	flags[city] = true;
	printf("city: 1, len: 0\n");

	while (true)
	{
		int min = INT_MAX;
		int tmp = -1;
		for (int i = 0; i < n; i++)
			if (!flags[i])
			{
				int len =  g->findMove(city, i);
				if  (min > len)
				{
					min = len;
					tmp = i;
				}
			}
		if (tmp == -1) break;

		printf("city: %d, len: %d\n", tmp + 1, g->findMove(0, tmp));

		city = tmp;
		flags[city] = true;
	}

	delete[] flags;
	delete g;

	scanf("%*s");

	return 0;
}

