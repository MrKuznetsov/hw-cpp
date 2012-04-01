#ifndef POINTLISTTEST_H
#define POINTLISTTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "pointlist.h"

class PointListTest : public QObject
{
  Q_OBJECT
public:
  explicit PointListTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      list = new PointList();
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

  void testListSize()
  {
      QVERIFY(list->size() == 0);
      list->addValue(228);
      list->addValue(666);
      list->addValue(21128);
      QVERIFY(list->size() == 3);
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
      list->addValue(666);
      QVERIFY(list->find(228) != 0);
      list->removeValue(228);
      QVERIFY(list->find(228) == 0);
  }
  void testGetPos()
  {
      list->addValue(228);
      list->addValue(666);
      list->addValue(21128);
      QVERIFY(list->get(2) == 666);
  }



private:
  PointList *list;

};
#endif // POINTLISTTEST_H
