/*HW 02.11.2011 Task1

 author: Slava Kuznecov
 email: svakelol@gmail.com

 estimate time 20min
 start time 19.27
 end time 19.44
*/
#include "stdafx.h"

struct Student
{
	int num; //Номер студента
	int synopsis; // Номер конспекта
	Student()
	{
		num = 0;
		synopsis = 0;  // Если 0, то студент ничего не сделал
	};
	Student(int n, int syn)
	{
		num = n;
		synopsis = syn;
	};
	void print();
};

int getSyn(Student **students, int num, int count)
{
	if (num < 4) 
		return num;
	else
		return getSyn(students, students[num - 1]->synopsis, count);
}

void Student::print()
{
	if (synopsis)
		printf("(%d) synopsis - %d\n", num, synopsis);
	else
		printf("(%d) FAILED\n", num);
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Reading from file...:\n");

	FILE * fd = fopen("FILE.TXT", "r"); 

	int count = 0;
	fscanf(fd, "%d", &count);

	Student **students = new Student*[count];
	for (int i = 0; i < count; i++)
		students[i] = NULL;

	int num = 0, syn = 0;
	while(fscanf(fd, "%d %d", &num, &syn) != EOF)
		students[num - 1] = new Student(num, syn);

	fclose(fd);

	for (int i = 0; i < count; i++)
		if (students[i])
			students[i]->synopsis = getSyn(students, students[i]->synopsis, count);

	printf("Results:\n");

	for (int i = 0; i < count; i++)
		if (students[i])
			students[i]->print();
		else
			printf("(%d) FAILED\n", i + 1);

	for (int i = 0; i < count; i++)
		if (students[i])
			delete students[i];
	delete[] students;

	scanf("%*s");

	return 0;
}

