#ifndef STACK_H
#define STACK_H

/**
@class Stack
Базовая абстракция класса стек
*/
class Stack
{
public:
    /// добавление элемента в конец стека
    virtual void push(int val) = 0;
    /// снятие элемента стека с конца
    virtual int pop() = 0;
    /// длина стека
    virtual int length() = 0;
};

#endif // STACK_H
