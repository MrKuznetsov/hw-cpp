#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"
#include "arraystack.h"
#include "pointstack.h"

/**
@class Calculator
Класс калькулятор, которому подается строка-выражение
а возвращается ответ
*/

class Calculator
{
public:
    Calculator();
    ~Calculator();
    /// инициализация калькулятора, именно здесь выбирается тип стека
    void init(bool array = true); //array(true) or pointer(false)
    /// метод, считающий строку-выражение
    int calc(char *c);

    /// статическая функция проверки символа на число
    static bool isDig(char c);
    /// статическая функция проверки символа на знак
    static bool isSign(char c);
private:
    Stack *st;
    int buf[100];
    char bufsize;

    void freeStack();
};

#endif // CALCULATOR_H
