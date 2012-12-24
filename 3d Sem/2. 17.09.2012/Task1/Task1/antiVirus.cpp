#include "antiVirus.h"

const int AntiVirus::getSafety()
{
	return safety;
}
void AntiVirus::print()
{
	std::cout << "AV: ";
}

AntiVirus *AntiVirus::Instance()
{
	static AntiVirus inst;
	return &inst;
}


void Nod32::print()
{
	AntiVirus::print();
	std::cout << "Nod32\n";
}
Nod32 *Nod32::Instance()
{
	static Nod32 inst;
	return &inst;
}

void Kaspersky::print()
{
	AntiVirus::print();
	std::cout << "Kaspersky\n";
}
Kaspersky *Kaspersky::Instance()
{
	static Kaspersky inst;
	return &inst;
}