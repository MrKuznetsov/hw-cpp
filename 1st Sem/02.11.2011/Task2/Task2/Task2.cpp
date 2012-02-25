/*HW 02.11.2011 Task2

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 60min
 start time 20.14
 end time 21.19
*/
#include "stdafx.h"
#include "hash.h"


int _tmain(int argc, _TCHAR* argv[])
{

	Hash *h = new Hash;
	h->init();
	printf("Reading from file...\n");

	FILE * fd = fopen("FILE.TXT", "r"); 

	char str[100];
	while(fscanf(fd, "%s", str) != EOF)
		h->add(str);

	fclose(fd);

	/*printf("Input word which needs to find\n");
	scanf("%s", str);

	HashList *tmp = h->find(str);
	if (tmp)
		printf("words count is %d\n", tmp->count);
	else
		printf("There is no \"%s\"", str);
	*/
	h->printStats();


	delete h;
	scanf("%*s");

	return 0;
}

