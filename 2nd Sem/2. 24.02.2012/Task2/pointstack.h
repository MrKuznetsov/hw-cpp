#ifndef POINTSTACK_H
#define POINTSTACK_H

#include "stack.h"

struct Node
{
    Node()
    {
        value = 0;
        pNext = 0;
    }

    int value;
    Node *pNext;
};

class PointStack : public Stack
{
private:
    Node *top;
    int len;
public:
    PointStack();
    ~PointStack();
    void push(int val);
    int pop();
    int length();
};

#endif // POINTSTACK_H
