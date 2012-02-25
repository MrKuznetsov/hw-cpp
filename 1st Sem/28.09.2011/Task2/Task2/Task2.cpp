/*HW 28.09.2011 Task2

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 60min
 start time 19.22 
 end time 20.31
*/
#include "stdafx.h"
#include "counter.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input count of counter: \n");
	int count = 0;
	scanf("%d", &count);

	printf("Input number of i-element(1..%d) of the list: \n", count);
	int i = 0;
	scanf("%d", &i);


    Counter *c = new Counter;
	c->initalize(count);

	int k = c->inverseRun(i);

	c->k = k;
	c->printRun();

	c->unInitalize();
	delete c;

	printf("Result k = %d", k);

	scanf("%*s");
	return 0;
}

