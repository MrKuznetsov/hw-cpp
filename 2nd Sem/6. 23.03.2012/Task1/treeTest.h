#ifndef TREETEST_H
#define TREETEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "tree.h"

class TreeTest : public QObject
{
  Q_OBJECT
public:
  explicit TreeTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      tree = new OperationLeaf();
  }

  void cleanup()
  {
      delete tree;
  }

  void testCalc()
  {
      string s = "(*(+11)(*34))";
      tree->build(s);
      QVERIFY(tree->calc() == 24);
  }


private:
  OperationLeaf *tree;

};
#endif // TREETEST_H
