#include <iostream>

#include "calculator.h"
#include "arraystackTest.h"
#include "pointstackTest.h"

using namespace std;

int main()
{
    ArrayStackTest t1;
    PointStackTest t2;
    QTest::qExec(&t1);
    QTest::qExec(&t2);

    cout << "Input sample" << endl;
    char s[100];
    gets(s);

    cout << "What kind of stack u wanna use?" << endl;
    cout << "Type 'p' or 'a' for pointer/array stack." << endl;
    char c;
    cin >> c;

    Calculator *cal = new Calculator();
    cal->init(c == 'p' ? false : true);

    int res = cal->calc(s);

    cout << "Result: " << res;

    return 0;
}

