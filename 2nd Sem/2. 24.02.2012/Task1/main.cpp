#include <iostream>


#include "list.h"
#include "pointlist.h"
#include "arraylist.h"

using namespace std;

int main()
{
    List *l;
    l = new ArrayList();
    for (int i = 0; i < 10; i++)
        l->addValue(i);

    cout << l->find(3);
    l->removeValue(2);

    delete l;

    return 0;
}

