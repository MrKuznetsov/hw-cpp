#ifndef FILESPIRAL_H
#define FILESPIRAL_H

#include "spiral.h"
#include <stdio.h>

class FileSpiral : public Spiral
{
public:
    void ñall(int *a, int N);
protected:
    void print(int a);
private:
    FILE *f;
};

#endif // FILESPIRAL_H
