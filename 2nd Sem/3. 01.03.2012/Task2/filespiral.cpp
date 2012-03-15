#include "filespiral.h"


void FileSpiral::print(int a)
{
    fprintf(f, "%d ", a);
}

void FileSpiral::Call(int *a, int N)
{
    f = fopen("FILE.TXT", "w");
    doSpiral(a, N);
    fclose(f);
}
