
#include "stdafx.h"
#include "list.h"

IntList *newList(int val)
{
	IntList *tmp = new IntList;
	tmp->value = val;
	tmp->next = NULL;
	return tmp;
}

void deleteList(IntList *list)
{
	IntList *tmp = list;
	while (tmp->next)
	{
		IntList *t = tmp->next;
		delete tmp;
		tmp = t;
	}
}

void addToSortedList(IntList *list, int value)
{
	IntList *next = list->next;
	IntList *prev = list;
	IntList *tmp = newList(value);
	while(next)
	{
		if (next->value >= value)
			break;
		prev = next;
		next = next->next; 
	}
	prev->next = tmp;
	tmp->next = next;
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