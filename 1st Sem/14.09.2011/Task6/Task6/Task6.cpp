/*HW 14.09.2011 Task6

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 8min
 start time 11.40
 end time 11.50
*/
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char s[50];
	char ps[50];

	printf("Input main string[50]: \n");
	gets(s);

	printf("Input substring[50]: \n");
	gets(ps);

	int i = 0;
	int j = 0;
	int count = 0;
	for (;;)
	{
		if (s[i] == 0)
			break;

		j = 0;
		for (;;)
		{
		    if (ps[j] == 0)
			{
				count++;
				i--;     //чтобы не пропустить символ
				break;
			}

			if (ps[j] != s[i])
			{
				if (j != 0)
					i--;  //чтобы не пропустить символ
				break;
			}
			j++;
			i++;
		}
		i++;
	}

	printf("Count of substring: %d",count);
	scanf("%d", &count);
	return 0;
}

