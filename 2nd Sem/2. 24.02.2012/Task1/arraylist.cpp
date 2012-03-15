#include "arraylist.h"

ArrayList::ArrayList()
{
    aLength = 0;
    capacity = addCapacity;
    vals = new int[capacity];
}

ArrayList::~ArrayList()
{
    delete[] vals;
}

void ArrayList::setLength(int len)
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

void ArrayList::addValue(int val)
{
    setLength(++aLength);
    vals[aLength - 1] = val;
}

void ArrayList::removeValue(int val)
{
    int j = 0;
    for (int i = 0; i < aLength; i++)
    {
        if (vals[i] != val)
            vals[j] = vals[i];
    }
    aLength = j + 1;
}

bool ArrayList::find(int val)
{
    for (int i = 0; i < aLength; i++)
    {
        if (vals[i] == val)
            return true;
    }
    return false;
}

int ArrayList::length()
{
    return aLength;
}

int ArrayList::get(int pos)
{
    return vals[pos];
}
