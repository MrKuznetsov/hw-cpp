#ifndef QUICKSORTTEST_H
#define QUICKSORTTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "quicksort.h"

class QuickSortTest : public QObject
{
  Q_OBJECT
public:
  explicit QuickSortTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      sort = new QuickSort();
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
  QuickSort *sort;
};


#endif // QUICKSORTTEST_H
