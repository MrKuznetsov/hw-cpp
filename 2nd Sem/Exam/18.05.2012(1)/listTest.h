#ifndef LISTTEST_H
#define LISTTEST_H



#include <QtCore/QObject>
#include <QtTest/QTest>

#include "list.h"

class ListTest : public QObject
{
  Q_OBJECT
public:
  explicit ListTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      list = new List<int>;
  }

  void cleanup()
  {
      delete list;
  }

  void testAdd()
  {
      list->add(100);
      list->add(200);
      QVERIFY(list->in(100));
  }
  void testRemove()
  {
      list->add(100);
      list->add(200);
      list->remove(100);
      QVERIFY(!list->in(100));
  }


private:
  List<int> *list;

};

#endif // LISTTEST_H
