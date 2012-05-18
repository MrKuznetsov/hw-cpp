#ifndef RANDOMCOMP_H
#define RANDOMCOMP_H

#include "compobject.h"

template<class T>
class RandomComp : public CompElement<T>
{
public:
     bool comp(T a, T b);
};

template<class T>
bool RandomComp<T>::comp(T a, T b)
{
    return a > b;
}

#endif // RANDOMCOMP_H
