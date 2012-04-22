#ifndef UNIQUELIST_H
#define UNIQUELIST_H

#include "list.h"

template<class T>
class UniqueList : public List<T>
{
public:
    class AddExsisting{};
    class RemoveNonExsisting{};
    void add(T v);
    void remove(T v);
};


template<class T>
void UniqueList<T>::add(T v)
{
    if (in(v))
        throw AddExsisting();
    else
        List<T>::add(v);

}

template<class T>
void UniqueList<T>::remove(T v)
{
    if (!in(v))
        throw RemoveNonExsisting();
    else
        List<T>::remove(v);

}

#endif // UNIQUELIST_H
