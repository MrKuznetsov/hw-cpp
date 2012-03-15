#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    virtual void push(int val) = 0;
    virtual int pop() = 0;
    virtual int length() = 0;
};

#endif // STACK_H
