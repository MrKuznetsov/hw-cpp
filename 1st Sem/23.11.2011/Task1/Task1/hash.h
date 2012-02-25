#pragma once

#include "stdafx.h"
#define NHASH 255

struct HashList
{
	char *str;
	int count; //кол-во слов
	HashList *next;

	HashList()
	{
		str = NULL;
		count = 0;
		next = NULL;
	};
	HashList(char *s, int c = 0)
	{
		count = c;
		next = NULL;
		int len = 0;
		for (len = 0; s[len]; len++);
		str = new char[len + 1];
		for (int i = 0; i < len; i++)
			str[i] = s[i];
		str[len] = 0;
	};
	~HashList()
	{
		if(str)
			delete[] str;
	};
};

void deleteHashList(HashList *l);

struct Hash
{
	int nHash;
	HashList **table;

	Hash()
	{
		nHash = NHASH;
	};

	~Hash()
	{
		for (int i = 0; i < nHash; i++)
			deleteHashList(table[i]);
		delete[] table;
	};

	void init()
	{
		table = new HashList*[nHash];
		for (int i = 0; i < nHash; i++)
			table[i] = NULL;
	};

	int hashFunc(char *s);
	HashList* add(char *s);
	HashList* find(char *s);

	void printStats();
};