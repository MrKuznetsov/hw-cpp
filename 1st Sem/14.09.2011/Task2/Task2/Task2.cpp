/*HW 14.09.2011 Task2

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 3min
 start time 21.15
 end time 21.17
*/
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input x y: \n");
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);

	int a = 0;
	while (x > y)
	{
		a++;
		x -= y;
	};
	printf("a = %d", a);

	scanf("%d", x);
	return 0;
}

