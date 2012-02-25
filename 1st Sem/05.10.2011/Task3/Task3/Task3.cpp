/*HW 05.10.2011 Task3

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 30min
 start time 15.56
 end time 16.26
*/
#include "stdafx.h"
#include <stdlib.h>
#include "list.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("0 - exit\n");
    printf("1 - add value to sorted list\n");
    printf("2 - remove value from list\n");
    printf("3 - print list\n");

	IntList *head = newList(-1);

	while(true)
	{
		printf("Input command:\n");
		int command = 0;
		scanf("%d", &command);
		int val = 0;
		switch (command)
		{
			case 0:
				deleteList(head);
				return 0;
			case 1:
				printf("Input value:\n");
				
				scanf("%d", &val);
				addToSortedList(head, val);
				break;
			case 2:
				printf("Input value:\n");
				
				scanf("%d", &val);
				removeValue(head, val);
				break;
			case 3:
				printList(head);
				break;
		};

	}
	
	deleteList(head);

	scanf("%*s");
	return 0;
}

