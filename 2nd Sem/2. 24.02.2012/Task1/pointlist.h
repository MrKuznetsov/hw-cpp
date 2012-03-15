#ifndef POINTLIST_H
#define POINTLIST_H

#include "list.h"

class PointList : public List
{
private:
    PointList *pNext;
    int value;
public:
    PointList();
    ~PointList();
    void addValue(int val);
    void removeValue(int val);
    bool find(int val);
    int length();
    int get(int pos = 0);
};

#endif // POINTLIST_H
