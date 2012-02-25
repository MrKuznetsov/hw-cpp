#include "stdafx.h"
#include "parser.h"

bool lvlPlusMinus(char *&c)
{
	delims(c); //пропускаем пробелы
	if (!lvlMulDiv(c)) //спускаемся на уровень вниз проверяя на первое слагаемое
		return false; //если ошибка 
	delims(c); //пропускаем пробелы
	while (*c == '+' || *c == '-') //проверяем на сложение и вычетание
	{
		c++; //смещаем позицию в строке
		if (!lvlMulDiv(c)) //спускаемся на уровень вниз тем самым прверяем на следующие слагаемые
			return false; //если ошибка
	}
	return true; //в случае успеха
}
bool lvlMulDiv(char *&c)
{
	delims(c); //пропускаем пробелы
	if (!lvlBrackNum(c)) //спускаемся на уровень вниз проверяя на первый множитель
		return false;
	delims(c); //пропускаем пробелы
	while (*c == '*' || *c == '/')
	{
		c++; //смещаем позицию в строке
		if (!lvlBrackNum(c)) //спускаемся на уровень вниз тем самым прверяем на следующие множители
			return false;
	}
	return true; //успех
}
bool lvlBrackNum(char *&c)
{
	delims(c); //удаляем пробелы
	if (*c == '(') //если открывающая скоба
	{
		c++; //смещаем позицию
		if (!lvlPlusMinus(c)) //запускаем анализатор снчала
			return false; //ошибка
		if (delims(c)) //удаляем пробелы и проверяем на конец строки
			return false;
		if (*c != ')') //если нет закр. скобы - ошибка
			return false;
		c++; //смещаем позицию
		return true; //успех
	} else //if (isDig(*c))
		return isFloat(c);
	//else return false;

}

bool isDig(char c)
{
	return (c <= '9' && c >= '0');
}

bool isFloat(char *&c)
{
	int state = -1;
	if (isDig(*c))
		state = 0;
	else if (*c == '-')
		state = 10;
	else
		return false;
	c++;
	while (true)
	{
		switch (state)
		{
		    case 10:
				if (isDig(*c))
				{
					c++;
					state = 0;
				}
				else
					state = -1;
				break;
/* 0 */    	case 0: 
				if (isDig(*c))
					c++;
				else if (*c == '.')
				{
					state = 1;
					c++;
				} else if (*c == 'e')
				{
					state = 3;
					c++;
				} else if (*c == 0)
					return true;
				else
					return true;
				break;
/* 1 */		case 1:
				if (*c == 0)
					state = -1;
				else if (isDig(*c))
				{
					state = 2;
					c++;
				} else
					state = -1;
				break;
/* 2 */		case 2:
				if (*c == 0)
					return true;
				else if (isDig(*c))
					c++;
				else if (*c == 'e')
				{
					state = 3;
					c++;
				} else
					return true;
				break;
/* 3 */	    case 3:
				if (*c == 0)
					state = -1;
				else if (*c == '+' || *c == '-')
				{
					state = 4;
					c++;
				} else if (isDig(*c))
				{
					state = 5;
					c++;
				} else
					state = -1;
				break;
/* 4 */	  	case 4:
				if (*c == 0)
					state = -1;
				else if (isDig(*c))
				{
					state = 5;
					c++;
				} else 
					state = -1;
				break;
/* 5 */	  	case 5:
				if (*c == 0)
					return true;
				else if (isDig(*c))
					c++;
				else 
					return true;
				break;
/* -1 */  	case -1:
				return false;
		}
	}
}

bool parse(char *c)
{
	char *tmp = c;
	return lvlPlusMinus(tmp) && delims(tmp);
}

bool delims(char *&c)
{
	while (*c == ' ')
		c++;
	return (*c == 0);
}