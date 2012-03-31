#ifndef STRINGHASH_H
#define STRINGHASH_H

#include <string>
#include "hash.h"
#include "stringlist.h"

const int N_HASH = 255;

using namespace std;
/// string list based hash table
class StringHash : public Hash
{
public:
    StringHash();

    void *add(string str);
    void remove(string str);
    void *find(string str);
    void status();
private:
    /// array of lists
    StringList aHash[N_HASH];
};

#endif // STRINGHASH_H
