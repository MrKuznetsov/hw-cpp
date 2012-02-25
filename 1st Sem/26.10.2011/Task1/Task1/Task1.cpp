/*HW 26.10.2011 Task1

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 5min + 60min tree module
 start time 17.08
 end time 18.37
*/
#include "stdafx.h"
#include <stdlib.h>
#include "tree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("0 - exit\n");
    printf("1 - add value to tree\n");
    printf("2 - remove value from tree\n");
    printf("3 - exists value from tree\n");
	printf("4 - print sorted tree from low to high\n");
	printf("5 - print sorted tree from high to low\n");
	
	Tree *t = NULL;

	while(true)
	{
		printf("Input command:\n");
		int command = 0;
		scanf("%d", &command);
		int val = 0;
		switch (command)
		{
			case 0:
				deleteTree(t);
				break;
		//		return 0;
			case 1:
				printf("Input added value:\n");
				
				scanf("%d", &val);
				if (!t)
					t = new Tree(val);
				else
					t->add(val);
				break;
			case 2:
				printf("Input removed value:\n");
				
				scanf("%d", &val);
				t = t->deleteVal(val);
				break;
			case 3:
				printf("Input existed value:\n");
				
				scanf("%d", &val);
				printf("%s\n", t->exists(val) ? "true" : "false");
				break;
			case 4:
				t->symmOrder();
				break;
			case 5:
				t->resymmOrder();
				break;
		};

	}
	
	deleteTree(t);

	scanf("%*s");
	return 0;
}

