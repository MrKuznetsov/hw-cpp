#ifndef BAGTEST_H
#define BAGTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "bag.h"

class BagTest : public QObject
{
  Q_OBJECT
public:
  explicit BagTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      bag = new Bag<int>;
  }

  void cleanup()
  {
      delete bag;
  }

  void testInsert_Find()
  {
      bag->insert(100);
      bag->insert(200);
      bag->insert(100);
      QVERIFY(bag->find(100));
      QVERIFY(bag->find(200));
      QVERIFY(bag->size() == 3);
  }

  void testIsEmpty()
  {
      QVERIFY(bag->isEmpty());
      bag->insert(100);
      QVERIFY(!bag->isEmpty());
  }

  void testErase()
  {
      bag->insert(100);
      bag->insert(100);
      bag->insert(200);
      bag->erase(100);
      QVERIFY(!bag->find(100));
      QVERIFY(bag->size() == 1);
  }

  void testClear()
  {
      bag->insert(100);
      bag->insert(100);
      bag->insert(200);
      bag->clear();
      QVERIFY(bag->size() == 0);
  }

  void testIterators()
  {
      bag->insert(100);
      bag->insert(100);
      bag->insert(200);
      bag->insert(300);
      bag->insert(200);

      Bag<int>::Iterator it = bag->begin();
      QVERIFY(*it == 100);
      it++;
      QVERIFY(*it == 100);
      it++;
      QVERIFY(*it == 200);
      it++;
      it++;
      it++;
      QVERIFY(it == bag->end());
  }



private:
  Bag<int> *bag;

};
#endif // BAGTEST_H
