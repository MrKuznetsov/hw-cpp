#ifndef BUBBLESORTTEST_H
#define BUBBLESORTTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "bubblesort.h"

class BubbleSortTest : public QObject
{
  Q_OBJECT
public:
  explicit BubbleSortTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      sort = new BubbleSort();
  }

  void cleanup()
  {
      delete sort;
  }

  void testSort()
  {
      int a[10];
      for (int i = 0; i < 9; i++)
          a[i] = i % 3;
      sort->sort(a, 10);
      QVERIFY(a[1] == 0);
  }


private:
  BubbleSort *sort;
};

#endif // BUBBLESORTTEST_H
