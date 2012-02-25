/*HW 23.11.2011 Task11

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 15min
 start time 19.50
 end time 20.02
*/
#include "stdafx.h"
#include <string.h>
#include "hash.h"

#define MAX_COUNT 100


int _tmain(int argc, _TCHAR* argv[])
{
	
	Hash *h = new Hash;
	h->init();

	FILE * fd = fopen("INPUT1.TXT", "r");
	FILE * fr = fopen("INPUT2.TXT", "r");
	FILE * fo = fopen("OUTPUT.TXT", "w");
	printf("Reading and writing:\n");
	char str[MAX_COUNT];
	while (fgets(str, MAX_COUNT, fd))
		h->add(str);

	char str2[MAX_COUNT];
	while(fgets(str2, MAX_COUNT, fr))
		if (h->find(str2))
		{
			fprintf(fo, "%s", str2);
			printf("%s", str2);
		}

	fclose(fd);
	fclose(fr);
	fclose(fo);

	delete h;

	scanf("%*s");

	return 0;
}

