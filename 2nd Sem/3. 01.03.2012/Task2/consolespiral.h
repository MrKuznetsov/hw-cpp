#ifndef CONSOLESPIRAL_H
#define CONSOLESPIRAL_H

#include "spiral.h"
#include <stdio.h>

/**
@class ConsoleSpiral
Класс, наследуемый от Spiral, записывает пройденный путь на консоль
*/
class ConsoleSpiral : public Spiral
{
public:
    void сall(int *a, int N);
protected:
    void print(int a);
};

#endif // CONSOLESPIRAL_H
