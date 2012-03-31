#ifndef RANDOMFUNCTION_H
#define RANDOMFUNCTION_H

#include <string>

#include "stringhash.h"

using namespace std;
/// example of hash function class
class RandomFunction : public HashFunction
{
public:
    int call(string str);
};

#endif // RANDOMFUNCTION_H
