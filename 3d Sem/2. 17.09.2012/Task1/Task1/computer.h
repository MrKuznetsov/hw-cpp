#pragma once

#include "antiVirus.h"
#include "os.h"
#include <iostream>

class Computer
{
private:
	OperatingSystem *os;
	bool isInfected;
	AntiVirus *av;
	Computer *connected;
public:
	Computer()
	{
		isInfected = false;
		av = NULL;
		connected = NULL;
	}

	Computer(OperatingSystem *pOs, AntiVirus *pAv = NULL)
	{
		os = pOs;
		av = pAv;
	}

	void print()
	{
		std::cout << "----------------\n";
		os->print();
		if (av)
			av->print();
		std::cout << "IsInfected: " << isInfected << '\n';
	}

	void tryToInfect()
	{
		int r = rand() % 100;

		float avChance = 0;
		if (av)
			avChance = av->getSafety() / 100;

		if (r > os->getChance() + os->getChance() * avChance)
		{
			std::cout << "PC IS INFECTED!\n";
			isInfected = true;
		}
	}

	void tryToHeal()
	{
		if (!av)
			return;

		int r = rand() % 80 + 20;
		if (r < av->getSafety())
		{
			std::cout << "AntiVirus delet virus from PC!\n";
			isInfected = false;
		}
	}

	const bool IsInfected()
	{
		return isInfected;
	}

	void setInfected(bool infect)
	{
		isInfected = infect;
	}

};