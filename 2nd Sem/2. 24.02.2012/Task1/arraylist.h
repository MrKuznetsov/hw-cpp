#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"

class ArrayList : public List
{
private:
    int *vals;
    int aLength;
    int capacity;
    static const int addCapacity = 32;

    void setLength(int len);
public:
    ArrayList();
    ~ArrayList();
    void addValue(int val);
    void removeValue(int val);
    bool find(int val);
    int length();
    int get(int pos = 0);
};

#endif // ARRAYLIST_H
