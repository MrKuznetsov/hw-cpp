#pragma once

bool parse(char *c);
bool lvlPlusMinus(char *&c);
bool lvlMulDiv(char *&c);
bool lvlBrackNum(char *&c);

bool delims(char *&c);
bool isDig(char c);

bool isFloat(char *&c);