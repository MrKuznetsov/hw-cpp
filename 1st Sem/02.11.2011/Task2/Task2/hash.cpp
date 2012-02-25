
#include "stdafx.h"
#include <string.h>
#include "hash.h"

void deleteHashList(HashList *l)
{
	if (!l) 
		return;
	HashList *tmp = l;
	if (tmp)
	{
		HashList *t = tmp->next;
		delete tmp;
		tmp = t;
	}
}

int Hash::hashFunc(char *s)
{
	int result = 0;
	for (int i = 0; s[i]; i++)
		result = (result + s[i]) % nHash;
	return result;
}

HashList* Hash::add(char *s)
{
	HashList *tmp = NULL;
	int index = hashFunc(s);
	for (tmp = table[index]; tmp; tmp = tmp->next)
		if (!strcmp(s, tmp->str))
			break;
	if (tmp)
		tmp->count++;
	else
	{
		tmp = new HashList(s, 1);
		tmp->next = table[index];
		table[index] = tmp;
	}

	return tmp;
}

HashList*  Hash::find(char *s)
{
	HashList *tmp = NULL;
	int index = hashFunc(s);
	for (tmp = table[index]; tmp; tmp = tmp->next)
		if (!strcmp(s, tmp->str))
			break;
	return tmp;
}

void Hash::printStats()
{
	HashList *tmp = NULL;
	int elemcount = 0;
	for (int i = 0; i < nHash; i++)
		if (table[i])
			for (tmp = table[i]; tmp; tmp = tmp->next)
			{
				printf("Count of \"%s\" is %d\n", tmp->str, tmp->count);
				elemcount++;
			};

	int free = 0;
	for (int i = 0; i < nHash; i++)
		if (!table[i])
			free++;
	printf("\n Stats:\n");
	printf("Count of FREE cells is %d(%d)\n", free, nHash);
	printf("Load factor is %f\n", float(elemcount)/float(nHash));
	int coll = 0;
	for (int i = 0; i < nHash; i++)
		if (table[i] && table[i]->next)
			coll++;
	printf("Count of collisions is %d\n", coll);

};