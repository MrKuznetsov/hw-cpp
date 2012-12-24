#include "Net.h"


Net::~Net()
{
	for (int i = 0; i < comps.size(); i++)
		delete comps[i];
}
void Net::init()
{
	srand(time(0));
	cout << "Matrix that shows connection of computers\n";

	for (int i = 0; i < NUM_COMPS; i++)
	{
		for (int j = 0; j < NUM_COMPS; j++)
		{
			matrix[i][j] = rand() % 2;
			if (i == j)
				matrix[i][j] = 0;
			cout << int(matrix[i][j]) << " ";
		}
		cout << endl;
	}

	vector<OperatingSystem *> oss;
	oss.push_back((OperatingSystem *)WindowsXP::Instance());
	oss.push_back((OperatingSystem *)Windows7::Instance());
	oss.push_back((OperatingSystem *)Linux::Instance());
	oss.push_back((OperatingSystem *)Mac::Instance());

	vector<AntiVirus *> avs;
	avs.push_back(NULL);
	avs.push_back((AntiVirus *)Kaspersky::Instance());
	avs.push_back((AntiVirus *)Nod32::Instance());

	for (int i = 0; i < NUM_COMPS; i++)
	{
		int r = rand() % oss.size();
		OperatingSystem *os = oss[r];

		r = rand() % avs.size();
		AntiVirus *av = avs[r];

		Computer *comp = new Computer(os, av);
		comp->setInfected(rand() % 2 * rand() % 2);
		comps.push_back(comp);
	}

}

void Net::setMatrix(char val, int x, int y)
{
	matrix[x][y] = val;
}

Computer *Net::addComp(bool isInfected, OperatingSystem *pOs, AntiVirus *pAv)
{
	Computer *comp = new Computer(pOs, pAv);
	comp->setInfected(isInfected);
	comps.push_back(comp);

	return comp;
}

void Net::doStep()
{
	for (int i = 0; i < comps.size(); i++)
	{
		Computer *comp = comps[i];
		if (comp->isInfected())
			comp->tryToHeal();
	}
	for (int i = 0; i < comps.size(); i++)
	{
		Computer *comp = comps[i];
		if (comp->isInfected())
			for (int j = 0; j < comps.size(); j++)
				if (matrix[i][j] && !comps[j]->isInfected())
				{
					comps[j]->tryToInfect();
					break;
				}

	}
}

void Net::showInf()
{
	for (int i = 0; i < comps.size(); i++)
	{
		comps[i]->print();
	}
}