#pragma once

#include <iostream>
#include "Net.h"

using namespace std;

#define SUCCESS(b, s) if (b) cout << "SUCCESS " << s << '\n'; else { cout << "FAILED!! " << s << '\n'; return false; }

class TestOS : OperatingSystem
{
protected:
	TestOS() : OperatingSystem()
	{
		chance = 0;
	}
public:
	void printOS()
	{
		OperatingSystem::printOS();
		std::cout << "TestOS";
	}

	static TestOS *Instance()
	{
		static TestOS inst;
		return &inst;
	}
};


class TestAV : AntiVirus
{
private:
	TestAV() {safety = 100;}
public:
	void print()
	{
		AntiVirus::print();
		std::cout << "TestAV\n";
	}

	static TestAV *Instance()
	{
		static TestAV inst;
		return &inst;
	}
};

class NetTest
{
private:
	Net *pNet;
	Computer *c1;
	Computer *c2;
public:
	NetTest(){}
	void Init()
	{
		pNet = new Net;
		pNet->setMatrix(1, 0, 0);
		pNet->setMatrix(1, 1, 0);
		pNet->setMatrix(1, 0, 1);
		pNet->setMatrix(1, 1, 1);

		c1 = pNet->addComp(true, (OperatingSystem *)TestOS::Instance());
		c2 = pNet->addComp(false, (OperatingSystem *)TestOS::Instance(), (AntiVirus *)TestAV::Instance());
	}
	void CleanUp()
	{
		delete pNet;
	}

	void Run()
	{
		cout << "STARTED NETWORK TEST\n**\n";
		Init();
			if (TestFull()) cout << "SUCCESS TEST\n\n";
		CleanUp();
		cout << "---------------------------\n";
	}

	bool TestFull()
	{
		cout << "TestNET\n";
		pNet->doStep();
		SUCCESS(c2->isInfected(), "INFECT");
		c2->tryToHeal();
		SUCCESS(!c2->isInfected(), "HEAL");

		return true;
	}
};