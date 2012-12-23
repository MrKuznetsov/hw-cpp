#include <stdio.h>
#include <tchar.h>

#include "Net.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Net * net = new Net();

	net->Init();

	while(true)
	{
		char i = 0;
		net->DoStep();

		i = getchar();
		if (i == 'q')
		{
			delete net;
			return 0;
		}

		if (i == 'i')
		{
			net->ShowInf();
			system("pause");
		}
		//system("pause");
	}
	return 0;
}

