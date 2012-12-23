#pragma once

#include <iostream>

class AntiVirus
{
protected:
	int safety;
public:
	AntiVirus()
	{
		safety = 0;
	}
	const int getSafety()
	{
		return safety;
	}

	virtual void print()
	{
		std::cout << "AV: ";
	}

	static AntiVirus *Instance()
	{
		static AntiVirus inst;
		return &inst;
	}
};

class Nod32 : AntiVirus
{
public:
	Nod32()
	{
		safety = 30;
	}
	const int getSafety()
	{
		return safety;
	}
	void print()
	{
		AntiVirus::print();
		std::cout << "Nod32\n";
	}
	static Nod32 *Instance()
	{
		static Nod32 inst;
		return &inst;
	}
};

class Kaspersky : AntiVirus
{
public:
	Kaspersky()
	{
		safety = 53;
	}
	const int getSafety()
	{
		return safety;
	}
	void print()
	{
		AntiVirus::print();
		std::cout << "Kaspersky\n";
	}
	static Kaspersky *Instance()
	{
		static Kaspersky inst;
		return &inst;
	}
};

