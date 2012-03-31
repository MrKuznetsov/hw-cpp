#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"
#include "arraystack.h"
#include "pointstack.h"

class Calculator
{
public:
    Calculator();
    ~Calculator();
    void init(bool array = true); //array(true) or pointer(false)

    int calc(char *c);

    static bool isDig(char c);
    static bool isSign(char c);
private:
    Stack *st;
    int buf[100];
    char bufsize;

    void freeStack();
};

#endif // CALCULATOR_H
