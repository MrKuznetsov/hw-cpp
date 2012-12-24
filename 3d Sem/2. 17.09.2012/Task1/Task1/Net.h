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
	~Net();
	void init();


	void setMatrix(char val, int x, int y);
	Computer *addComp(bool isInfected, OperatingSystem *pOs, AntiVirus *pAv = NULL);

	void doStep();
	void showInf();

};