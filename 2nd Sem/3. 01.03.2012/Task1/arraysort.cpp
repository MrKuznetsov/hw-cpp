#include "arraysort.h"

void ArraySort::swap(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}
