#include "pointstack.h"

PointStack::PointStack()
{
    len = 0;
    top = 0;
}

PointStack::~PointStack()
{
    Node *tmp = top;
    while (tmp)
    {
        Node *t = tmp->pNext;
        delete tmp;
        tmp = t;
    }
}

void PointStack::push(int val)
{
    Node *p = new Node();
    p->pNext = top;
    p->value = val;
    top = p;
    len++;
}

int PointStack::pop()
{
    if (len == 0)
        return 0;
    len = len > 0 ? len - 1 : 0;
    int tmp = top->value;
    Node *p = top->pNext;
    delete top;
    top = p;

    return tmp;
}

int PointStack::length()
{
    return len;
}
