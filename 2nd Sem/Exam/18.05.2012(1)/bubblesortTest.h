#ifndef BUBBLESORTTEST_H
#define BUBBLESORTTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "bubblesort.h"
#include "randomcomp.h"

class BubbleSortTest : public QObject
{
  Q_OBJECT
public:
  explicit BubbleSortTest(QObject *parent = 0) : QObject(parent) {}
private slots:
  void init()
  {
      sort = new BubbleSort<int>;
  }

  void cleanup()
  {
      delete sort;
  }

  void testArraySort()
  {
      vector<int> v;
      v.push_back(5);
      v.push_back(4);
      v.push_back(1);
      v.push_back(6);
      v.push_back(3);
      v.push_back(7);
      v.push_back(2);

      sort->doArraySort(&v, &r);

      for (int i = 0; i < 7; i++)
          QVERIFY(v[i] == i + 1);
  }

  void testListSort()
  {
      List<int> l;
      l.add(2);
      l.add(1);
      l.add(4);
      l.add(3);

      sort->doListSort(&l, &r);
      List<int> *tmp = l.next;
      for (int i = 0; i < 4; i++)
      {
          QVERIFY(tmp->val == i + 1);
          tmp = tmp->next;
      }
  }


private:
  BubbleSort<int> *sort;
  RandomComp<int> r;
};

#endif // BUBBLESORTTEST_H
