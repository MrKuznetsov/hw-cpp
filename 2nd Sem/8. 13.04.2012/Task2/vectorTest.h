#ifndef VECTORTEST_H
#define VECTORTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "vector.h"

class VectorTest : public QObject
{
  Q_OBJECT
public:
  explicit VectorTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
     // tree = new OperationLeaf();
  }

  void cleanup()
  {
      //delete tree;
  }

  void testPlusMinus()
  {
      v1[0] = 123;
      v1[1] = 56;
      v1[2] = 45;

      v2[0] = 89;
      v2[1] = 4;
      v2[2] = 12;

      Vector<int> pRes = v1 + v2 + 9;
      Vector<int> mRes = v1 - v2 - 3;

      QCOMPARE(pRes[0], 123 + 89 + 9);
      QCOMPARE(pRes[1], 56  + 4  + 9);
      QCOMPARE(pRes[2], 45  + 12 + 9);
      QCOMPARE(mRes[0], 123 - 89 - 3);
      QCOMPARE(mRes[1], 56  - 4  - 3);
      QCOMPARE(mRes[2], 45  - 12 - 3);
  }
  void testMulDiv()
  {
      v1[0] = 10;
      v1[1] = 50;
      v1[2] = 1;

      v2[0] = 5;
      v2[1] = 10;
      v2[2] = 15;

      Vector<int> pRes = v1 * 2;
      Vector<int> mRes = v2 / 5;
      QCOMPARE(pRes[0], 20);
      QCOMPARE(pRes[1], 100);
      QCOMPARE(pRes[2], 2);
      QCOMPARE(mRes[0], 1);
      QCOMPARE(mRes[1], 2);
      QCOMPARE(mRes[2], 3);
  }
  void testScalar()
  {
      v1[0] = 10;
      v1[1] = 50;
      v1[2] = 1;

      v2[0] = 5;
      v2[1] = 10;
      v2[2] = 15;

      int pRes = v1.scalar(v2);
      QCOMPARE(pRes, 565);
  }

  void testisNul()
  {
      v1[0] = 0;
      v1[1] = 0;
      v1[2] = 0;

      v2[0] = 5;
      v2[1] = 10;
      v2[2] = 15;

      QVERIFY(v1.isNul());
      QVERIFY(!v2.isNul());
  }
  void testCompare()
  {
      v1[0] = 5;
      v1[1] = 10;
      v1[2] = 15;

      v2[0] = 5;
      v2[1] = 10;
      v2[2] = 15;

      QVERIFY(v1 == v2);
  }

  void testCopy()
  {
      v1[0] = 3;
      v1[1] = 4;
      v1[2] = 0;
      v2 = v1;
      QCOMPARE(v2[0], 3);
      QCOMPARE(v2[1], 4);
      QCOMPARE(v2[2], 0);
  }

private:
  Vector<int> v1,v2;

};
#endif // VECTORTEST_H
