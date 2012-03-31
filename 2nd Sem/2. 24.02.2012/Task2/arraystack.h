#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();
    void push(int val);
    int pop();
    int length();
private:
    int *aVals;
    int aLength;
    int aCapacity;
    static const int addCapacity = 32;

    void setLength(int len);
};

#endif // ARRAYSTACK_H
