#ifndef QUEUENODETEST_H
#define QUEUENODETEST_H


#include <QtCore/QObject>
#include <QtTest/QTest>

#include "queuenode.h"

class QueueNodeTest : public QObject
{
  Q_OBJECT
public:
  explicit QueueNodeTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      q = new QueueNode<int>();
  }

  void cleanup()
  {
      delete q;
  }

  void testAddValueToSorted()
  {
      q->addToSorted(666, 6);
      q->addToSorted(777, 7);
      q->addToSorted(228, 1);
      q->addToSorted(1488, 10);
      QueueNode<int> *t = q->next;
      QVERIFY(t->value == 1488);
      t = t->next;
      QVERIFY(t->value == 777);
      t = t->next;
      QVERIFY(t->value == 666);
      t = t->next;
      QVERIFY(t->value == 228);
  }


private:
  QueueNode<int> *q;

};


#endif // QUEUENODETEST_H
