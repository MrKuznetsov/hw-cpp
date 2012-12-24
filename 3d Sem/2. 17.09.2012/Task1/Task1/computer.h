#pragma once

#include "antiVirus.h"
#include "os.h"
#include <iostream>

class Computer
{
private:
	OperatingSystem *os;
	bool infected;
	AntiVirus *av;
public:
	Computer();
	Computer(OperatingSystem *pOs, AntiVirus *pAv = NULL);

	void print();
	void tryToInfect();

	void tryToHeal();

	const bool isInfected();

	void setInfected(bool infect);

};