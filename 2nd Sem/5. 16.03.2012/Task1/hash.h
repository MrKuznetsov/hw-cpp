#ifndef HASH_H
#define HASH_H

#include <string>
#include "hashfunction.h"
#include "hashlist.h"

using namespace std;
/// basic abstract hash class
class Hash
{
public:
    virtual ~Hash(){};
    /// add string to hash table
    virtual HashList *add(string str) = 0;
    /// remov string from hash table
    virtual void remove(string str) = 0;
    /// find string from hash table
    virtual HashList *find(string str) = 0;
    /// print some information about hash
    virtual void status() = 0;

    void setFunc(HashFunction *f)
    {
        func = f;
    }

protected:
    HashFunction *func;
};

#endif // HASH_H
