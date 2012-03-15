#ifndef FILESPIRAL_H
#define FILESPIRAL_H

#include "spiral.h"
#include <stdio.h>

class FileSpiral : public Spiral
{
private:
    FILE *f;
protected:
    void print(int a);
public:
    void Call(int *a, int N);
};

#endif // FILESPIRAL_H
