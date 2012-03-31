#include "pointlist.h"

PointList::PointList() : pNext(0), value(0)
{

}

PointList::~PointList()
{
    PointList *tmp = pNext;
    while (tmp)
    {
        PointList *t = tmp->pNext;
        delete tmp;
        tmp = t;
    }
}

void PointList::addValue(int val)
{
    PointList *p = this;
    while (p->pNext)
        p = p->pNext;

    PointList *tmp = new PointList();
    tmp->value = val;
    p->pNext = tmp;
}

void PointList::removeValue(int val)
{
    PointList *next = pNext;
    PointList *prev = this;
    while(next)
    {
        if (next->value == val)
        {
            prev->pNext = next->pNext;
            delete next;
            next = prev;
        }
        prev = next;
        next = next->pNext;
    }

}

bool PointList::find(int val)
{
    PointList *p = this;
    while (p)
    {
        if (p->value == val)
            return true;
        p = p->pNext;
    }
    return false;
}

int PointList::size()
{
    int len = 0;
    PointList *p = this;
    while (p)
    {
        len++;
        p = p->pNext;
    }
    return len;
}

int PointList::get(int pos)
{
    int j = 0;
    PointList *p = this;
    while (p && j < pos)
    {
        j++;
        p = p->pNext;
    }
    return p ? p->value : -1;
}
