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
public:
    PointStack();
    ~PointStack();
    void push(int val);
    int pop();
    int length();
private:
    Node *top;
    int len;
};

#endif // POINTSTACK_H
