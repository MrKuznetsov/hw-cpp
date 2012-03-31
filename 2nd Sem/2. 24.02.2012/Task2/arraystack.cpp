#include "arraystack.h"

ArrayStack::ArrayStack() : aLength(0)
{
    aCapacity = addCapacity;
    aVals = new int[aCapacity];
}

ArrayStack::~ArrayStack()
{
    delete[] aVals;
}

void ArrayStack::setLength(int len)
{
    if (len > aCapacity)
    {
        delete[] aVals;
        while (len > aCapacity)
            aCapacity += addCapacity;
        aVals = new int[aCapacity];
    }
    aLength = len;
}

void ArrayStack::push(int val)
{
    setLength(++aLength);
    aVals[aLength - 1] = val;
}

int ArrayStack::pop()
{
    if (aLength == 0)
        return 0;
    return aVals[--aLength];
}

int ArrayStack::length()
{
    return aLength;
}

