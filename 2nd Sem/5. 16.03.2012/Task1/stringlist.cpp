#include "stringlist.h"

StringList::StringList() : count(0), next(0)
{
    next = 0;
}

StringList::~StringList()
{
    delete next;
}

HashList *StringList::add(string s)
{
    StringList *p = this;
    while (p->next)
    {
        if (p->next->str == s)
        {
            p->next->count++;
            return p->next;
        }
        p = p->next;
    }

    StringList *tmp = new StringList();
    tmp->count = 1;
    tmp->str = s;
    p->next = tmp;
    return tmp;
}

void StringList::remove(string s)
{
    StringList *pNext = next;
    StringList *pPrev = this;
    while(pNext)
    {
        if (pNext->str == s)
        {
            pPrev->next = pNext->next;

            pNext->next = 0;
            delete pNext;

            pNext = pPrev;
            return;
        }
        pPrev = pNext;
        pNext = pNext->next;
    }
}

HashList *StringList::find(string s)
{
    StringList *p = next;

    while (p)
    {
        if (p->str == s)
            return p;
        p = p->next;
    }
    return 0;
}
