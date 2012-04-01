#ifndef ARRAYSORT_H
#define ARRAYSORT_H

/**
@class ArraySort
Базовый абстрактный класс сортировки массива
*/
class ArraySort
{
public:
    /// сортировка на вкод подается сам массив, его длина, и порядок сортировки
    virtual void sort(int* a, int len, bool fromLow = true) = 0;

    static void swap(int &a, int &b);
};

#endif // ARRAYSORT_H
