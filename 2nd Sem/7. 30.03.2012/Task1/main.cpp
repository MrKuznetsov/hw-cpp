#include <iostream>

using namespace std;

class RandomException{};

class Exception
{
public:
    Exception()
    {
        cout << "OMG!!! TRY HARD!!\n";
    }
    ~Exception()
    {
        cout << "I'M DEAD! FUCK IT!!\n";
    }
};

void exceptionTest()
{
    Exception e;
    throw RandomException();
}

int main()
{
    try
    {
        exceptionTest();
    }
    catch (RandomException)
    {
        cout << "WOW!!! I'M GOD";
    }

    return 0;
}

