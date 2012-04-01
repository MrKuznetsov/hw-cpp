#include <iostream>

#include "arraysort.h"
#include "bubblesort.h"

#include "bubblesortTest.h"

using namespace std;

int main()
{
    BubbleSortTest t1;
    QTest::qExec(&t1);

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
    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;


    return 0;
}

