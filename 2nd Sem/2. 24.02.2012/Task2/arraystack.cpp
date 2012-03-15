#include "arraystack.h"

ArrayStack::ArrayStack()
{
    aLength = 0;
    capacity = addCapacity;
    vals = new int[capacity];
}

ArrayStack::~ArrayStack()
{
    delete[] vals;
}

void ArrayStack::setLength(int len)
{
    if (len > capacity)
    {
        delete[] vals;
        while (len > capacity)
            capacity += addCapacity;
        vals = new int[capacity];
    }
    aLength = len;
}

void ArrayStack::push(int val)
{
    setLength(++aLength);
    vals[aLength - 1] = val;
}

int ArrayStack::pop()
{
    if (aLength == 0)
        return 0;
    return vals[--aLength];
}

int ArrayStack::length()
{
    return aLength;
}

