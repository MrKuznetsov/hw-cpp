#pragma once

struct IntList
{
	int value; //степень
	int factor;//коэффициент
	IntList *next;
	IntList(int val, int k = 1)
	{
		value = val;
		factor = k;
		next = 0;
	}
};

//IntList *newList(int val);

void deleteList(IntList *list);

IntList *addToSortedList(IntList *list, int value, int k);
IntList *addToEnd(IntList *list, int value, int k);

void removeValue(IntList *list, int value);

void printList(IntList *list);

//-------------------------------------\\

bool equals(IntList *p, IntList *q);
int value(IntList *p, int x);
void add(IntList *p, IntList *q, IntList *r);