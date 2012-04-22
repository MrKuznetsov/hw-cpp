#include <iostream>
#include "listqueue.h"

#include "queuenodeTest.h"
#include "listqueueTest.h"

using namespace std;

int main()
{
    QueueNodeTest t1;
    ListQueueTest t2;
    QTest::qExec(&t1);
    QTest::qExec(&t2);
    cout << "Hello World!" << endl;
    return 0;
}

