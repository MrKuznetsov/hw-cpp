#include "consolespiral.h"

void ConsoleSpiral::print(int a)
{
    printf("%d ", a);
}

void ConsoleSpiral::Call(int *a, int N)
{
    doSpiral(a, N);
}
