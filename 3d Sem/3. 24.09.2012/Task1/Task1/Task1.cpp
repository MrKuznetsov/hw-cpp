// Task1.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include "test.h"
#include "treeTest.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	TreeTest test2;
	test2.Run();
	IteratorTest test;
	test.Run();

	system("pause");
	return 0;
}

