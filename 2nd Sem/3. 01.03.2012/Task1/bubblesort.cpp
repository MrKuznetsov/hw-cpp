#include "bubblesort.h"

void BubbleSort::sort(int* a, int len, bool fromLow)
{
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if ((a[i] > a[j] && fromLow) || (a[i] < a[j] && !fromLow))
                    swap(a[i], a[j]);
}
