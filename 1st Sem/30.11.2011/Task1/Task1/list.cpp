
#include "stdafx.h"
#include "list.h"

/*IntList *newList(int val)
{
	IntList *tmp = new IntList(val);
	//tmp->value = val;
	tmp->next = NULL;
	return tmp;
}*/

int pow(int a, int b)
{
	int res = 1;
	while(b > 0)
	{
		if (b % 2 == 1)
			res *= a;
		b /= 2;
		a *= a;
	}
	return res;
}

void deleteList(IntList *list)
{
	IntList *tmp = list;
	while (tmp)
	{
		IntList *t = tmp->next;
		delete tmp;
		tmp = t;
	}
}

IntList *addToSortedList(IntList *list, int value, int k)
{
	IntList *next = list->next;
	IntList *prev = list;
	IntList *tmp = new IntList(value, k);
	while(next)
	{
		if (next->value <= value)
			break;
		prev = next;
		next = next->next; 
	}
	prev->next = tmp;
	tmp->next = next;
	return tmp;
}
IntList *addToEnd(IntList *list, int value, int k)
{
	IntList *next = list;
	while(next->next)
		next = next->next;
	IntList *tmp = new IntList(value, k);
	next->next = tmp;
	return tmp;
}

void removeValue(IntList *list, int value)
{
	IntList *next = list->next;
	IntList *prev = list;
	IntList *tmp = NULL;
	while(next)
	{
		if (next->value == value)
		{
			prev->next = next->next;
			delete next;
			next = prev;
		}
		prev = next;
		next = next->next; 
	}
}

void printList(IntList *list)
{
	IntList *tmp = list->next;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

bool equals(IntList *p, IntList *q)
{
	IntList *tmp = p->next;
	IntList *tmq = q->next;
	while (true)
	{
		if (!tmp && !tmq)
			return true;

		if (!tmp  || !tmq)
			return false;

		if (tmp->factor != tmq->factor || tmp->value != tmq->value)
			return false;

		tmp = tmp->next;
		tmq = tmq->next;
	}	
}

int value(IntList *p, int x)
{
	IntList *tmp = p->next;
	int res = 0;

	while (tmp)
	{
		res += pow(x, tmp->value) * tmp->factor;
		tmp = tmp->next;
	}
	return res;
}

void add(IntList *p, IntList *q, IntList *r)
{
	IntList *tmp = p->next;
	IntList *tmq = q->next;
	deleteList(r->next);
	r->next = NULL;
	
	while (true)
	{
		if (!tmp && !tmq)
			break;
		if (tmp && tmq)
		{
			if (tmp->value == tmq->value)
			{
				addToEnd(r, tmp->value, tmp->factor + tmq->factor);
				tmp = tmp->next;
				tmq = tmq->next;
			} else
			if (tmp->value > tmq->value)
			{
				addToEnd(r, tmp->value, tmp->factor);
				tmp = tmp->next;
			} else
			{
				addToEnd(r, tmq->value, tmq->factor);
				tmq = tmq->next;
			}

		} else
		if (tmp)
		{
			addToEnd(r, tmp->value, tmp->factor);
			tmp = tmp->next;
		} else
		{
			addToEnd(r, tmq->value, tmq->factor);
			tmq = tmq->next;
		}
	}
};