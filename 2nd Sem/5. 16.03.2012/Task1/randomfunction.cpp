#include "randomfunction.h"

int RandomFunction::call(string str)
{
    int result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        result = (result + str.data()[i]) % N_HASH;

        if (i == 5)
            break; //для быстроты выполнения
    }
    return result;
}
