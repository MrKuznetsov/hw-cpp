#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "queue.h"
#include "queuenode.h"

/// queue class inheritide from Queue based on list
template <class T>
class ListQueue : public Queue<T>
{
public:
    class DequeueFromEmpty {};
    ListQueue()
    {
        head = new QueueNode<T>();
    }
    ~ListQueue()
    {
        delete head;
    }

    void enqueue(T val, int p);
    T dequeue();
private:
    QueueNode<T> *head;
};

/************************************************************************************

************************************************************************************/

template <class T>
void ListQueue<T>::enqueue(T val, int p)
{
    head->addToSorted(val, p);
}

template <class T>
T ListQueue<T>::dequeue()
{
    if (!head->next)
        throw ListQueue<T>::DequeueFromEmpty();
    else
    {
        QueueNode<T> *tmp = head->next;
        head->next = tmp->next;
        T res = tmp->value;

        tmp->next = 0;
        delete tmp;

        return res;
    }
}


#endif // LISTQUEUE_H
