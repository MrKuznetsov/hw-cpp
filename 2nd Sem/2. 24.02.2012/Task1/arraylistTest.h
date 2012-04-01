#ifndef ARRAYLISTTEST_H
#define ARRAYLISTTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "arraylist.h"

class ArrayListTest : public QObject
{
  Q_OBJECT
public:
  explicit ArrayListTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      list = new ArrayList();
  }

  void cleanup()
  {
      delete list;
  }

  void testAddValue()
  {
      list->addValue(100);
      QVERIFY(list->find(100));
  }
  void testRemoveValue()
  {
      list->addValue(228);
      list->removeValue(228);
      list->removeValue(234);
      QVERIFY(list->find(228) == false);
  }
  void testFindValue()
  {
      QVERIFY(list->find(228) == 0);
      list->addValue(228);
      QVERIFY(list->find(228) != 0);
      list->removeValue(228);
      QVERIFY(list->find(228) == 0);
  }

  void testSize()
  {
      list->addValue(228);
      list->addValue(222);
      list->addValue(21128);
      QVERIFY(list->size() == 3);
  }


private:
  ArrayList *list;

};

#endif // ARRAYLISTTEST_H
