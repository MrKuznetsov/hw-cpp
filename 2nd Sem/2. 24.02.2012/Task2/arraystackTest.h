#ifndef ARRAYSTACKTEST_H
#define ARRAYSTACKTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "arraystack.h"

class ArrayStackTest : public QObject
{
  Q_OBJECT
public:
  explicit ArrayStackTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      stack = new ArrayStack();
  }

  void cleanup()
  {
      delete stack;
  }

  void testPushPop()
  {
      stack->push(100);
      stack->push(228);
      QVERIFY(stack->pop() == 228);
  }

  void testSize()
  {
      stack->push(100);
      stack->push(100);
      stack->push(100);
      QVERIFY(stack->length() == 3);
  }


private:
  ArrayStack *stack;

};

#endif // ARRAYSTACKTEST_H
