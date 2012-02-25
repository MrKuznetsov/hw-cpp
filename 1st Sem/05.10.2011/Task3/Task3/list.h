#pragma once

struct IntList
{
	int value;
	IntList *next;
};

IntList *newList(int val);

void deleteList(IntList *list);

void addToSortedList(IntList *list, int value);

void removeValue(IntList *list, int value);

void printList(IntList *list);