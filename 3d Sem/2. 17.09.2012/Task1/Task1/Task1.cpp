#include <stdio.h>
#include <tchar.h>

#include "Net.h"
#include "test.h"

int _tmain(int argc, _TCHAR* argv[])
{
	NetTest test;
	test.Run();

	Net * net = new Net();

	net->init();

	while(true)
	{
		char i = 0;
		net->doStep();

		i = getchar();
		if (i == 'q')
		{
			delete net;
			return 0;
		}

		if (i == 'i')
		{
			net->showInf();
			system("pause");
		}
		//system("pause");
	}
	return 0;
}

