#ifndef POINTSTACKTEST_H
#define POINTSTACKTEST_H
#include <QtCore/QObject>
#include <QtTest/QTest>

#include "pointstack.h"

class PointStackTest : public QObject
{
  Q_OBJECT
public:
  explicit PointStackTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      stack = new PointStack();
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
  PointStack *stack;

};

#endif // POINTSTACKTEST_H
