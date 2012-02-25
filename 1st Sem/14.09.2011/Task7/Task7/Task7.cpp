/*HW 14.09.2011 Task7

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 5min
 start time 11.58
 end time 12.02
*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool isSimple(int n)
{
	for(int i = 2; i <= n/2; i++)
		if( (n % i) == 0 )
			return 0;  
    return 1;  
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input a: \n");
	int a;
	cin >> a;
	printf("Simple nums:\n");
	for (int i = 2; i <= a; i++)
		if (isSimple(i))
			printf("%d \n", i);


	cin >> a;
	return 0;
}

