#ifndef POINTSTACK_H
#define POINTSTACK_H

#include "stack.h"

/// описание элемента списка
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

/**
@class PointStack
 ласс, наследуемый от Stack, позвол€ющий работать со стеком
на списках
*/

class PointStack : public Stack
{
public:
    PointStack();
    ~PointStack();
    void push(int val);
    int pop();
    int length();
private:
    /// верхний элемент списка
    Node *top;
    /// длина списка
    int len;
};

#endif // POINTSTACK_H
