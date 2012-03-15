#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "stack.h"

class ArrayStack : public Stack
{
private:
    int *vals;
    int aLength;
    int capacity;
    static const int addCapacity = 32;

    void setLength(int len);
public:
    ArrayStack();
    ~ArrayStack();
    void push(int val);
    int pop();
    int length();
};

#endif // ARRAYSTACK_H
