#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "sort.h"

template<class T>
class BubbleSort: public Sort<T>
{
public:
    void doListSort(List<T> *l,CompElement<T> *c);
    void doArraySort(vector<T> *a, CompElement<T> *c);
private:
    static void swap(T &a, T &b);
};

template<class T>
void BubbleSort<T>::swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
void BubbleSort<T>::doListSort(List<T> *l, CompElement<T> *c)
{
    for (List<T> *i = l->next; i; i = i->next)
        for (List<T> *j = i->next; j; j = j->next)
            if (c->comp(i->val, j->val))
                    swap(i->val, j->val);
}

template<class T>
void BubbleSort<T>::doArraySort(vector<T> *a, CompElement<T> *c)
{
    int len = a->size();
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if (c->comp(a->data()[i], a->data()[j]))
            {
                T tmp = a->data()[i];
                a->data()[i] = a->data()[j];
                a->data()[j] = tmp;
            }
}


#endif // BUBBLESORT_H
