#ifndef ARRAYSORT_H
#define ARRAYSORT_H

class ArraySort
{
public:
    virtual void sort(int* a, int len, bool fromLow = true) = 0;

    static void swap(int &a, int &b);
};

#endif // ARRAYSORT_H
