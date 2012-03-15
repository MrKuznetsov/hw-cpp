#ifndef CONSOLESPIRAL_H
#define CONSOLESPIRAL_H

#include "spiral.h"
#include <stdio.h>

class ConsoleSpiral : public Spiral
{
protected:
    void print(int a);
public:
    void Call(int *a, int N);
};

#endif // CONSOLESPIRAL_H
