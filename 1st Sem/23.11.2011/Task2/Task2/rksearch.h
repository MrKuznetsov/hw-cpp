#pragma once

#define CHARS 256 //кол-во символов в алфавите
#define MOD 7919 //простое число по котрому считается хэш ф.

inline int hashch(char c, int last);

int strFind(char *s, char *ps);