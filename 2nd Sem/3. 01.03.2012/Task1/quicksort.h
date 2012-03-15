#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "arraysort.h"

class QuickSort : public ArraySort
{
private:
    void qsort(int *a, int low, int high, bool fromLow = true );
public:
    void sort(int* a, int len, bool fromLow = true);
};

#endif // QUICKSORT_H
