#ifndef STRINGLIST_H
#define STRINGLIST_H

#include <string>
#include "hashlist.h"

using namespace std;

class StringList : public HashList
{
public:
    /// count of strings
    int count;
    string str;
    StringList *next;

    StringList();
    ~StringList();

    /// add some string to end of list
    HashList *add(string s);
    /// remove string from list
    void remove(string s);
    /// find string in list
    HashList *find(string s);
};

#endif // STRINGLIST_H
