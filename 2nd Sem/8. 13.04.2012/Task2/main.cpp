#include <iostream>

using namespace std;

#include "vectorTest.h"

int main()
{
    VectorTest t1;
    QTest::qExec(&t1);

    Vector<int> m,n,p;
    m[0] = 1220;
    n[1] = 10;
    p = m + n;
    cout << p[0] << p[1];
    return 0;
}

