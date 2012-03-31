#ifndef CONSOLESPIRAL_H
#define CONSOLESPIRAL_H

#include "spiral.h"
#include <stdio.h>

class ConsoleSpiral : public Spiral
{
public:
    void ñall(int *a, int N);
protected:
    void print(int a);
};

#endif // CONSOLESPIRAL_H
