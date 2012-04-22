#include <iostream>
#include "tree.h"

#include "treeTest.h"

using namespace std;

int main()
{
    TreeTest t1;
    QTest::qExec(&t1);

    return 0;
}

