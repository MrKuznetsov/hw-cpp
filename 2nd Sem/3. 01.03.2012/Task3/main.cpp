#include <iostream>

#include "arraysort.h"
#include "bubblesort.h"

using namespace std;

int main()
{

    printf("Input N, NxN matrix\n");
    int N = 0;
    scanf("%d", &N);

    int **a = new int*[N];

    for(int x = 0; x < N; x++)
    {
        a[x] = new int[N];
        for (int y = 0; y < N; y++)
            a[x][y] = rand() % 10;
    }

    for(int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf("%d ", a[y][x]);
        printf("\n");
    }

    ArraySort *sort = new BubbleSort();
    sort->sort(a, N);

    printf("\n");
    for(int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf("%d ", a[y][x]);
        printf("\n");
    }


    return 0;
}

