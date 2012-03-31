#include "calculator.h"

Calculator::Calculator()
{
   st = 0;
}
Calculator::~Calculator()
{
    delete st;
}

void Calculator::init(bool array)
{
    delete st;
    if (array)
        st = new ArrayStack();
    else
        st = new PointStack();
}

bool Calculator::isDig(char c)
{
    return (c >= '0' && c <= '9');
}

bool Calculator::isSign(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

void Calculator::freeStack()
{
    char c = 0;
    while (true)
    {
        c = st->pop();
        if (c == 0 || c == '(')
            return;
        if (isSign(c))
            bufsize--;
        switch (c)
        {
        case '+':
            buf[bufsize - 1] += buf[bufsize];
            break;
        case '-':
            buf[bufsize - 1] -= buf[bufsize];
            break;
        case '*':
            buf[bufsize - 1] *= buf[bufsize];
            break;
        case '/':
            buf[bufsize - 1] /= buf[bufsize];
            break;
        };
    }
}

int Calculator::calc(char *s)
{
    bufsize = 0;

    int i = 0;
    char c = 0;
    while (s[i])
    {
        if (isDig(s[i]))
            buf[bufsize++] = s[i] - '0';

        if (s[i] == '+' || s[i] == '-')
            freeStack();

        if (isSign(s[i]) || s[i] == '(')
            st->push(s[i]);

        if (s[i] == ')')
            freeStack();
        i++;
    }
    freeStack();

    return buf[0];
}
