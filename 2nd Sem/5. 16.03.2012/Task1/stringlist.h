#ifndef STRINGLIST_H
#define STRINGLIST_H

#include <string>

using namespace std;

class StringList
{
public:
    /// count of strings
    int count;
    string str;
    StringList *next;

    StringList();
    ~StringList();

    /// add some string to end of list
    StringList *add(string s);
    /// remove string from list
    void remove(string s);
    /// find string in list
    StringList *find(string s);
};

#endif // STRINGLIST_H
