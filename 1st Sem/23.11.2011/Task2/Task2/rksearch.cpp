#include "stdafx.h"
#include "rksearch.h"
#include <string>

inline int hashch(char c, int last)
{
	return (last * CHARS + c) % MOD;
}

int strFind(char *s, char *ps)
{
	int slen = strlen(s);
	int pslen = strlen(ps);

	int shash = 0, pshash = 0;
	int k = 1;
	for (int i = 0; i < pslen; i++)
	{
		shash = hashch(s[i], shash);
		pshash = hashch(ps[i], pshash);
		if (i < pslen - 1)
			k = k * CHARS % MOD;
	}
	for (int i = pslen; i < slen + 1; i++)
	{
		if (shash == pshash)
			if (!strncmp(&s[i - pslen], ps, pslen))
				printf("%d ", i - pslen);
			//	return i - pslen;
		shash = ( CHARS * (shash + MOD - (s[i - pslen] * k % MOD)) + s[i]) % MOD;
	}
	return -1;
}