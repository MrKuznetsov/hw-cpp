#ifndef QUEUENODE_H
#define QUEUENODE_H

/// special list class for ListQueue class
template <class T>
class QueueNode
{
public:
    T value;
    /// priority
    int p;
    QueueNode *next;

    QueueNode()
    {
        next = 0;
    }
    ~QueueNode()
    {
        delete next;
    }
    /// add to sorterd list with priority
    void addToSorted(T val, int pp);
};

template <class T>
void QueueNode<T>::addToSorted(T val, int pp)
{
    QueueNode<T>* pPrev = this;
    QueueNode<T>* pNext = next;

    QueueNode<T> *tmp = new QueueNode<T>;
    tmp->value = val;
    tmp->p = pp;

    while(pNext)
    {
        if (pNext->value < val)
            break;
        pPrev = pNext;
        pNext = pNext->next;
    }

    pPrev->next = tmp;
    tmp->next = pNext;
}

#endif // QUEUENODE_H
