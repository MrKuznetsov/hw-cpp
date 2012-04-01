#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "arraysort.h"
/**
@class BubbleSort
Класс, наследуемый от ArraySort, является пузырьковой сортировкой
*/
class BubbleSort : public ArraySort
{
public:
    void sort(int** a, int len, bool fromLow = true);
};

#endif // BUBBLESORT_H
