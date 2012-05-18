#ifndef LIST_H
#define LIST_H

template<class T>
class List
{
public:
    List<T> *next;
    T val;

    List():next(0){}
    virtual ~List()
    {
       delete next;
    }

    virtual void add(T v);
    virtual void remove(T v);
    bool in(T v);
    int size();
};

/**********************************************************************
 **********************************************************************/

template<class T>
void List<T>::add(T v)
{
    List<T> *tmp = this;//new List<T>;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = new List<T>;;
    tmp->next->val = v;
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
int List<T>::size()
{
    int count = 0;
    List<T> *tmp = next;
    while(tmp)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
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
