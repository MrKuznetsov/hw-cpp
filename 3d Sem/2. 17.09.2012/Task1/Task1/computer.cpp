#include "computer.h"

Computer::Computer() : infected(false), av(NULL)
{

}

Computer::Computer(OperatingSystem *pOs, AntiVirus *pAv) : os(pOs), av(pAv), infected(false)
{

}

void Computer::print()
{
	std::cout << "----------------\n";
	os->print();
	if (av)
		av->print();
	std::cout << "IsInfected: " << infected << '\n';
}

void Computer::tryToInfect()
{
	int r = rand() % 100;

	float avChance = 0;
	if (av)
		avChance = av->getSafety() / 100;

	if (r > os->getChance() + os->getChance() * avChance)
	{
		std::cout << "PC IS INFECTED!\n";
		infected = true;
	}
}

void Computer::tryToHeal()
{
	if (!av)
		return;

	int r = rand() % 80 + 20;
	if (r < av->getSafety())
	{
		std::cout << "AntiVirus delet virus from PC!\n";
		infected = false;
	}
}

const bool Computer::isInfected()
{
	return infected;
}

void Computer::setInfected(bool infect)
{
	infected = infect;
}
