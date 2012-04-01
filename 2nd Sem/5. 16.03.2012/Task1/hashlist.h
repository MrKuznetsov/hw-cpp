#ifndef HASHLIST_H
#define HASHLIST_H

#include <string>

using namespace std;

class HashList
{
public:
    virtual ~HashList(){};

    /// add some string to end of list
    virtual HashList *add(string s) = 0;
    /// remove string from list
    virtual void remove(string s) = 0;
    /// find string in list
    virtual HashList *find(string s) = 0;
};

#endif // HASHLIST_H
