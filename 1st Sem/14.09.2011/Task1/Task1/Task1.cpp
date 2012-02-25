/*HW 14.09.2011 Task 1

 author: Slava Kuznecov
 email: svakelol@gmail.com

*/
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input x: \n");
	int x;
	scanf("%d", &x);
	printf("x^4+x^3+x^2+x = %d", (x*x+1)*(x*x+x));
	
	scanf("%d", &x);
	return 0;
}

