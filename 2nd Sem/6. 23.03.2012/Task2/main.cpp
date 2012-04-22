#include <iostream>

#include "listSet.h"
#include "listSetTest.h"

using namespace std;

int main()
{
    ListSetTest t1;
  //  PointListTest t2;
    QTest::qExec(&t1);
 //   QTest::qExec(&t2);
    return 0;
}

