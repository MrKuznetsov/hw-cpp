#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <string>

using namespace std;

/// abstract class for hasg function
class HashFunction
{
public:
    virtual ~HashFunction(){};
    virtual int call(string str) = 0;
};

#endif // HASHFUNCTION_H
