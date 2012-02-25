/*HW 30.11.2011 Task1

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 30min
 start time 14.05
 end time 14.42
*/
#include "stdafx.h"
#include "list.h"

void getPolinomial(IntList *p)
{
	int x = 0; //pow
	int k = 0; //factor

	deleteList(p->next);
	p->next = NULL;

	while (true)
	{
		scanf("%d %d", &x, &k);
		if (!k)
			break;
		addToSortedList(p, x, k);
	}
}
void printPolinomial(IntList *p)
{
	IntList *tmp = p->next;

	while (tmp)
	{
		printf("%d*x^%d ", tmp->factor, tmp->value);
		tmp = tmp->next;
		if (tmp)
			printf("+ ");
	}
	printf("\n");
}
IntList *getPoliPram(IntList *p, IntList *q, IntList *r, char c)
{
	if (c == 'p')
		return p;
	else if (c == 'q')
		return q;
	else
	   return r;
}


int _tmain(int argc, _TCHAR* argv[])
{
	IntList *p =  new IntList(0, 0);
	IntList *q =  new IntList(0, 0);
	IntList *r =  new IntList(0, 0);

	printf("0  - exit\n");
    printf("1p - write polinomial, where 'p' is polinomial(p or q)\n");
	printf("2p - print polinomial, where 'p' is polinomial(p or q or r)\n");
    printf("3  - equals polinomial(p and q)\n");
    printf("4p - value polinomial(p or q or r)\n");
	printf("5  - add p to q and resault will be in r\n");

	while(true)
	{
		printf("Input command:\n");
		int command = 0;
		scanf("%d", &command);
		char c = 0;
		int val = 0;
		switch (command)
		{
		    case 0:
				deleteList(p);
				deleteList(q);
				deleteList(r);
				return 0;
			case 1:
				scanf("%c", &c);
				printf("Input firstly pow then factor(8 3 - 3*x^8");
				getPolinomial(getPoliPram(p, q, r, c));
				break;
			case 2:
				scanf("%c", &c);
				printPolinomial(getPoliPram(p, q, r, c));
				break;
			case 3:
				if (equals(p, q))
					printf("p and q are equals\n");
				else
					printf("p and q aren't equals\n");
				break;
			case 4:
				scanf("%c", &c);
				printf("input x\n");
				scanf("%d", &val);
				printf("result is %d\n", value(getPoliPram(p, q, r, c), val));
				break;
			case 5:
				add(p, q, r);
				break;
		}
	}
	return 0;
}

