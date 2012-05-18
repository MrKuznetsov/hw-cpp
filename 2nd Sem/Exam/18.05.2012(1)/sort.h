#ifndef SORT_H
#define SORT_H

#include "list.h"
#include "compobject.h"
#include <vector>

using namespace std;

template<class T>
class Sort
{
public:
    virtual ~Sort(){}
    virtual void doListSort(List<T> *l,CompElement<T> *c) = 0;
    virtual void doArraySort(vector<T> *a, CompElement<T> *c) = 0;
};

#endif // SORT_H
