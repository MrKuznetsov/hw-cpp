#include <iostream>


#include "list.h"
#include "pointlist.h"
#include "arraylist.h"

#include "arraylistTest.h"
#include "pointlistTest.h"

using namespace std;

int main()
{
    ArrayListTest t1;
    PointListTest t2;
    QTest::qExec(&t1);
    QTest::qExec(&t2);

    List *l;
    l = new ArrayList();
    for (int i = 0; i < 10; i++)
        l->addValue(i);

    cout << l->find(3);
    l->removeValue(2);

    delete l;

    return 0;
}

