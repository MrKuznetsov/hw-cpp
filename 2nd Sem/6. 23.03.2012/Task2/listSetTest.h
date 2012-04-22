#ifndef LISTSETTEST_H
#define LISTSETTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "listSet.h"

class ListSetTest : public QObject
{
  Q_OBJECT
public:
  explicit ListSetTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      list = new ListSet<int>();
  }

  void cleanup()
  {
      delete list;
  }

  void testAddValue()
  {
      list->add(100);
      list->add(10);
      QVERIFY(list->in(10));
      QVERIFY(list->in(100));

      list->add(100);
      list->setBegin();
      list->getNext();
      list->getNext();
      list->getNext();
      QVERIFY(list->isEnd());
  }

  void testRemoveValue()
  {
      list->add(100);
      list->add(10);
      QVERIFY(list->in(10));
      QVERIFY(list->in(100));
      list->remove(10);
      QVERIFY(!list->in(10));
  }

  void testIntersection()
  {
      ListSet<int> *list2 = new ListSet<int>();
      list->add(1);
      list->add(3);
      list->add(5);

      list2->add(1);
      list2->add(2);
      list2->add(5);

      list->intersection(list2);

      QVERIFY(list->in(1));
      QVERIFY(list->in(5));
      QVERIFY(!list->in(2));
      QVERIFY(!list->in(3));


      delete list2;
  }
  void testcombine()
  {
      ListSet<int> *list2 = new ListSet<int>();
      list->add(1);
      list->add(3);
      list->add(5);

      list2->add(1);
      list2->add(2);
      list2->add(5);

      list->combine(list2);

      QVERIFY(list->in(1));
      QVERIFY(list->in(5));
      QVERIFY(list->in(2));
      QVERIFY(list->in(3));


      delete list2;
  }


private:
  ListSet<int> *list;

};

#endif // LISTSETTEST_H
