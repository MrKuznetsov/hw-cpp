//           COUNTER.CPP        
#include "stdafx.h"
#include "counter.h"


CountList *newCount(int num)
{
	CountList *tmp = new CountList;
	tmp->num = num;
	tmp->next = NULL;
	return tmp;
}

CountList *newCount(int num, int count)
{
	CountList *first = newCount(num);
	CountList *tmp = first;

	for (int i = num + 1; i < count + num; i++)
	{
		tmp->next =  newCount(i);
		tmp = tmp->next;
	};
	tmp->next = first;
	return first;
}

void deleteCount(CountList *l)
{
	if (!l) 
		return;

	int num = l->num;
	CountList *tmp = l->next;
	while (tmp->num != num)
	{
		CountList *t = tmp->next;
		delete tmp;
		tmp = t;
	}
	delete l;
}

void deleteFromCount(CountList *l)
{
	int num = l->next->num;
	CountList *tmp = l->next->next;
	
	delete l->next;
	l->num = num;
	l->next = tmp;
}

void Counter::initalize(int c, int k)
{
	firstElem = newCount(1, c);
	this->k = k;
	count = c;
};

void Counter::reInit()
{
	firstElem = newCount(1, count);
}

void Counter::unInitalize()
{
	deleteCount(firstElem);
};

int Counter::run()
{
	int j = count;
	CountList *tmp = firstElem;
	while (j > 1)
	{
		for (int i = 0; i < k; i++)
			tmp = tmp->next;
     	deleteFromCount(tmp);
		j--;
	}; 
	firstElem = tmp;
	return tmp->num;
};

void Counter::printRun()
{
	unInitalize();
	reInit();
	int j = count;
	CountList *tmp = firstElem;

	CountList *t = firstElem;
	for (int i = 0; i < j; i++)
	{
		printf("%d ", t->num);
		t = t->next;
	}
	printf("\n");

	while (j > 1)
	{
		for (int i = 0; i < k; i++)
			tmp = tmp->next;
     	deleteFromCount(tmp);
		j--;
		t = tmp;
		for (int i = 0; i < j; i++)
	    {
		    printf("%d ", t->num);
			t = t->next;
	    }
		printf("\n");
	}; 
	firstElem = tmp;
};

int Counter::inverseRun(int i)
{
	int res = 0;
	while(true)
	{
		this->unInitalize();
		this->reInit();

		k = res;

		int j = run();
		if (j == i)
			break;
		res++;
	}

	return res;
};