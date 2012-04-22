#ifndef LISTQUEUETEST_H
#define LISTQUEUETEST_H


#include <QtCore/QObject>
#include <QtTest/QTest>

#include "listqueue.h"

class ListQueueTest : public QObject
{
  Q_OBJECT
public:
  explicit ListQueueTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      q = new ListQueue<int>();
  }

  void cleanup()
  {
      delete q;
  }

  void testEn_DeQueue()
  {
      q->enqueue(666, 6);
      q->enqueue(777, 7);
      q->enqueue(228, 1);
      q->enqueue(1488, 10);
      QVERIFY(q->dequeue() == 1488);
      QVERIFY(q->dequeue() == 777);
      QVERIFY(q->dequeue() == 666);
      QVERIFY(q->dequeue() == 228);
  }
  void testDequeueEmpty()
  {
      try
      {
         q->dequeue();
      }
      catch(ListQueue<int>::DequeueFromEmpty)
      {
          QWARN("Its not bad (:");
      }
  }


private:
  ListQueue<int> *q;

};


#endif // LISTQUEUETEST_H
