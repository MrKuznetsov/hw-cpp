#pragma once

struct CountList
{
	int num;
	CountList *next;
};

CountList *newCount(int num);
CountList *newCount(int num, int count);
void deleteCount(CountList *l);
void deleteFromCount(CountList *l);

struct Counter
{
	int k;
	int count; //кол-во элементов в считалочке
	CountList *firstElem; 

	void initalize(int c, int k = 0);
	void reInit();
	void unInitalize();
	int run();
	void printRun();
	int inverseRun(int i);
};
