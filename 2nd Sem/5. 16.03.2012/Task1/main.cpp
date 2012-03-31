#include <iostream>
#include <string>
#include "hash.h"
#include "stringhash.h"
#include "randomfunction.h"

#include "stringhashTest.h"
#include "stringlistTest.h"

using namespace std;

int main()
{
    StringListTest t1;
    StringHashTest t2;
    QTest::qExec(&t1);
    QTest::qExec(&t2);


    RandomFunction f[3];
    StringHash h;
    h.setFunc(&f[0]);

    int answer = -1;
    int x = 0;
    string s;

    cout << "Commands:\n0 - exit\n";
    cout << "1 - add string to hash\n";
    cout << "2 - remove string from hash\n";
    cout << "3 - find string from hash\n";
    cout << "4 - get status\n";
    cout << "5 - set func(1..3)\n";

    while (answer != 0)
    {
        cout << "Command: ";
        cin >> answer;
        if (answer == 1)
        {
            cout << "Input string\n";
            cin >> s;
            h.add(s);

        }
        else if (answer == 2)
        {
            cout << "Input string\n";
            cin >> s;
            h.remove(s);
        }
        else if (answer == 3)
        {
            cout << "Input string\n";
            cin >> s;
            if (h.find(s))
                 cout << "Finded\n";
             else
                 cout << "Not Finded\n";
        }
        else if (answer == 4)
        {
            h.status();
        }
        else if (answer == 5)
        {
            cout << "Input number\n";
            cin >> x;
            h.setFunc(&f[x]);
        }
    }
    return 0;
}

