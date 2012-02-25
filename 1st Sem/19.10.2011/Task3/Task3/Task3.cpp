/*HW 19.10.2011 Task3

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 20min
 start time 15.45
 end time 16.07
*/
#include "stdafx.h"
#include <stdlib.h>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Reading from file FILE.TXT...\n");

	 FILE * fd = fopen("FILE.TXT", "r"); 
	 char c = 0;
	 bool isQ = false;
	 while ((c = fgetc(fd)) != EOF)
	 {
		 if (c == '"')
			 isQ = !isQ;
		 if (c == '/' && fgetc(fd) == '/' && !isQ)
		 {
			 while ( c != '\n')
			 {
				  c = fgetc(fd);
				  if (c == EOF) 
					  break;
				  printf("%c", c);
		     }
			 isQ = false;
		 }
	 }
	 fclose(fd);

	scanf("%*s");
	return 0;
}

