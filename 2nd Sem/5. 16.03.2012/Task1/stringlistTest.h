#ifndef STRINGLISTTEST_H
#define STRINGLISTTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "stringlist.h"

class StringListTest : public QObject
{
  Q_OBJECT
public:
  explicit StringListTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      list = new StringList();
  }

  void cleanup()
  {
      delete list;
  }

  void testAddString()
  {
      list->add("gbfj");
      QVERIFY(list->find("gbfj"));
  }
  void testRemoveString()
  {
      list->add("gbfj");
      list->remove("gbfj");
      list->remove("ertedth");
      QVERIFY(list->find("gbfj") == 0);
  }
  void testFindString()
  {
      QVERIFY(list->find("gbfj") == 0);
      list->add("gbfj");
      QVERIFY(list->find("gbfj") != 0);
      list->remove("gbfj");
      QVERIFY(list->find("gbfj") == 0);
  }


private:
  StringList *list;

};

#endif // STRINGLISTTEST_H
