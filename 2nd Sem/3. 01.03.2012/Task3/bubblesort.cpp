#include "bubblesort.h"

void BubbleSort::sort(int** a, int len, bool fromLow)
{
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if ((a[i][0] > a[j][0] && fromLow) || (a[i][0] < a[j][0] && !fromLow))
                    swap(a[i], a[j]);
}
