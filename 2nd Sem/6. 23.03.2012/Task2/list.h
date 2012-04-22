#ifndef LIST_H
#define LIST_H

template<class T>
class List
{
public:
    List<T> *next;
    T val;

    List():next(0){}
    ~List()
    {
       delete next;
    }

    void add(T v);
    bool in(T v);
    void remove(T v);
};

/**********************************************************************
 **********************************************************************/

template<class T>
void List<T>::add(T v)
{
    List<T> *tmp = new List<T>;
    tmp->val = v;
    tmp->next = next;
    next = tmp;
}

template<class T>
bool List<T>::in(T v)
{
    List<T> *p = next;
    while (p)
    {
        if (p->val == v)
            return true;
        p = p->next;
    }
    return false;
}

template<class T>
void List<T>::remove(T v)
{
    List<T> *pNext = next;
    List<T> *pPrev = this;
    while(pNext)
    {
        if (pNext->val == v)
        {
            pPrev->next = pNext->next;
            pNext->next = 0;
            delete pNext;
            pNext = pPrev;
        }
        pPrev = pNext;
        pNext = pNext->next;
    }
}



#endif // LIST_H
