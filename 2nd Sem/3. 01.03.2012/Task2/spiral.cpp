#include "spiral.h"

void Spiral::doSpiral(int *a, int N)
{
    int x = N / 2;
    int y = N / 2;

    int step = 1;
    int dir = 1;
    while(true)
    {
        for(int i = 0; i < step; i++)
        {
            print(a[y * N + x]);
            y -= dir;
        }
        if ( y == -1)
            break;
        for(int i = 0; i < step; i++)
        {
            print(a[y * N + x]);
            x -= dir;
        }
        step++;
        dir = -dir;
    }
}
