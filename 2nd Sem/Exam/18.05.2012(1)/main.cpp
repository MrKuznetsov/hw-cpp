#include <iostream>

#include "bubblesortTest.h"
#include "listTest.h"

using namespace std;

int main()
{
    BubbleSortTest t1;
    ListTest t2;
    QTest::qExec(&t2);
    QTest::qExec(&t1);
    //cout << "Hello World!" << endl;
    return 0;
}

