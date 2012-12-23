#pragma once

#include "antiVirus.h"
#include "os.h"
#include "computer.h"
#include <vector>

#define NUM_COMPS 10

using namespace std;

class Net
{
private:
	vector<Computer *> comps;
	char matrix[NUM_COMPS][NUM_COMPS];
public:
	~Net()
	{
		for (int i = 0; i < comps.size(); i++)
			delete comps[i];
	}
	void Init()
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

	void DoStep()
	{
		for (int i = 0; i < NUM_COMPS; i++)
		{
			Computer *comp = comps[i];
			if (comp->IsInfected())
				comp->tryToHeal();
			if (comp->IsInfected())
				for (int j = 0; j < NUM_COMPS; j++)
					if (matrix[i][j] && !comps[j]->IsInfected())
					{
						comps[j]->tryToInfect();
						break;
					}

		}
	}

	void ShowInf()
	{
		for (int i = 0; i < NUM_COMPS; i++)
		{
			comps[i]->print();
		}
	}

};