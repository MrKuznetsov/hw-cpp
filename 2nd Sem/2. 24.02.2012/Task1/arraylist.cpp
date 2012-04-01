#include "arraylist.h"

ArrayList::ArrayList() : length(0)
{
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
    length = len;
}

void ArrayList::addValue(int val)
{
    setLength(++length);
    vals[length - 1] = val;
}

void ArrayList::removeValue(int val)
{
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (vals[i] != val)
            vals[j++] = vals[i];
    }
    length = j;
}

bool ArrayList::find(int val)
{
    for (int i = 0; i < length; i++)
    {
        if (vals[i] == val)
            return true;
    }
    return false;
}

int ArrayList::size()
{
    return length;
}

int ArrayList::get(int pos)
{
    return vals[pos];
}
