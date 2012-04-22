#ifndef LISTSET_H
#define LISTSET_H

#include "set.h"
#include "list.h"

template<class T>
class ListSet : public Set<T>
{
public:
    ListSet()
    {
        head = new List<T>;
    }

    ~ListSet(){}
    virtual void add(T elem);
    virtual void remove(T elem);
    virtual bool in(T elem);
    virtual void intersection(Set<T> *s);
    virtual void combine(Set<T> *s);
//protected:
    bool isEnd()
    {
        return !current;
    }
    T getNext()
    {
        T res = current->val;
        current = current->next;
        return res;
    }

    void setBegin()
    {
        current = head;
    }

    List<T> *current;
private:
    List<T> *head;
};


/**********************************************************************
 **********************************************************************/

template<class T>
void ListSet<T>::add(T elem)
{
    if (!head->in(elem))
        head->add(elem);
}

template<class T>
void ListSet<T>::remove(T elem)
{
    head->remove(elem);
}

template<class T>
bool ListSet<T>::in(T elem)
{
    return head->in(elem);
}

template<class T>
void ListSet<T>::intersection(Set<T> *s)
{
    List<T> *tmp = head->next;
    List<T> *th = new List<T>;
    while(tmp)
    {
        if (s->in(tmp->val))
            th->add(tmp->val);
        tmp = tmp->next;
    }
    delete head;
    head = th;
}

template<class T>
void ListSet<T>::combine(Set<T> *s)
{
    s->setBegin();
    T val = s->getNext();
    while(!s->isEnd())
    {
        add(val);
        val = s->getNext();
    }
}

#endif // LISTSET_H
