#ifndef QUEUE_H
#define QUEUE_H

/// Base abstract queue class
template <class T>
class Queue
{
public:
    virtual ~Queue(){};
    /// add to queue 'val' with priority 'p'
    virtual void enqueue(T val, int p) = 0;
    /// return high-priority value from queue
    virtual T dequeue() = 0;
};

#endif // QUEUE_H
