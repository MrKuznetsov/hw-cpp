#ifndef STRINGHASHTEST_H
#define STRINGHASHTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "stringhash.h"
#include "randomfunction.h"

class StringHashTest : public QObject
{
  Q_OBJECT
public:
  explicit StringHashTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      hash = new StringHash();
      hash->setFunc(&f);
  }

  void cleanup()
  {
      delete hash;
  }

  void testAddString()
  {
      hash->add("gbfj");
      QVERIFY(hash->find("gbfj"));
  }
  void testRemoveString()
  {
      hash->add("gbfj");
      hash->remove("gbfj");
      hash->remove("ertedth");
      QVERIFY(hash->find("gbfj") == 0);
  }
  void testFindString()
  {
      QVERIFY(hash->find("gbfj") == 0);
      hash->add("gbfj");
      QVERIFY(hash->find("gbfj") != 0);
      hash->remove("gbfj");
      QVERIFY(hash->find("gbfj") == 0);
  }


private:
  StringHash *hash;
  RandomFunction f;

};

#endif // STRINGHASHTEST_H
