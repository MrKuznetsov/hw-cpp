#include "stdafx.h"
#include "graph.h"
#include <string>
#include <limits>

int Graph::findMove(int a, int b)
{
	bool *flags = new bool[points];
	int *len = new int[points];
	for (int i = 0; i < points; i++)
	{
		flags[i] = false;
		len[i] = INT_MAX;
	}
	
	len[a] = 0;
	flags[a] = true;
	int point = a;

	while (true)
	{
		for (int i  = 0; i < points; i++)
			if (m->get(point, i) && (len[i] > len[point] + m->get(point, i)))
				len[i] = len[point] + m->get(point, i);


		int min = INT_MAX;
	    point = -1;

		for (int i = 0; i < points; i++)
			if (!flags[i] && min > len[i])
			{
				point = i;
				min = len[i];
			}

		if (point == b || point == -1)
			break;
		flags[point] = true;
	}

	int l = len[b];
	delete[] flags;
	delete[] len;
	
	return l;
}