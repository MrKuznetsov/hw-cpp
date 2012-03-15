#include "quicksort.h"


void QuickSort::qsort(int *a, int low, int high, bool fromLow)
{
    int i = low;
    int j = high;
    int x = a[(low + high) / 2];
    do {
        while((a[i] < x && fromLow) || (a[i] > x && !fromLow))
            i++;
        while((a[j] < x && !fromLow) || (a[j] > x && fromLow))
            j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    while(i <= j);

    if(low < j) qsort(a, low, j);
    if(i < high) qsort(a, i, high);
}

void QuickSort::sort(int* a, int len, bool fromLow)
{
    qsort(a, 0, len - 1, fromLow);
}
