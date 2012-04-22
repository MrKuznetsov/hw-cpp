#ifndef UNIQUELISTTEST_H
#define UNIQUELISTTEST_H


#include <QtCore/QObject>
#include <QtTest/QTest>

#include "uniqueList.h"

class UniqueListTest : public QObject
{
  Q_OBJECT
public:
  explicit UniqueListTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      list = new UniqueList<int>;
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

      try
      {
          list->add(200);
      }
      catch (UniqueList<int>::AddExsisting)
      {
          QWARN("WHY ARE YOU TRYING TO ADD THIS VALUE??");
      }
  }
  void testRemove()
  {
      list->add(100);
      list->add(200);
      list->remove(100);
      QVERIFY(!list->in(100));

      try
      {
          list->remove(100);
      }
      catch (UniqueList<int>::RemoveNonExsisting)
      {
          QWARN("WHY ARE YOU TRYING TO REMOVE THIS VALUE??");
      }
  }


private:
  UniqueList<int> *list;

};

#endif // UNIQUELISTTEST_H
