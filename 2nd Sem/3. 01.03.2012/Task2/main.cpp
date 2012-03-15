#include <iostream>

#include "spiral.h"
#include "filespiral.h"
#include "consolespiral.h"

using namespace std;

int main()
{
    printf("Input odd N, NxN - count of array\n");
    int N = 0;
    scanf("%d", &N);

    int *a = new int[N*N];

    for(int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            a[y * N + x] = rand() % 10;
            printf("%d ", a[y * N + x]);
        }
        printf("\n");
    }
    printf("\n");

    Spiral *s = new FileSpiral();

    s->Call(a, N);


    return 0;
}

