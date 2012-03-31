#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"
/**
@class ArrayList
Класс, наследуемый от List, позволяющий работать над списками,
построенных на массивах
*/
class ArrayList : public List
{
public:
    ArrayList();
    ~ArrayList();
    void addValue(int val);
    void removeValue(int val);
    bool find(int val);
    int size();
    int get(int pos = 0);
private:
    int *vals;
    int length;
    int capacity;
    static const int addCapacity = 32;

    void setLength(int len);
};

#endif // ARRAYLIST_H
