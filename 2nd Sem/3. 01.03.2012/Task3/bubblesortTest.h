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
      int **a = new int*[10];
      for (int i = 0; i < 10; i++)
      {
          a[i] = new int[10];
          for (int j = 0; j < 9; j++)
              a[i][j] = 9 - i + j;
      }
      sort->sort(a, 10);    
      QVERIFY(a[1][0] == 1);

      for (int i = 0; i < 10; i++)
          delete[] a[i];
      delete[] a;

  }


private:
  BubbleSort *sort;
};

#endif // BUBBLESORTTEST_H
