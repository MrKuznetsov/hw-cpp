#pragma once

#include <iostream>

class AntiVirus
{
protected:
	int safety;
	AntiVirus() : safety(0){}
public:
	const int getSafety();
	virtual void print();

	static AntiVirus *Instance();
};

class Nod32 : AntiVirus
{
private:
	Nod32() {safety = 30;}
public:
	void print();

	static Nod32 *Instance();
};

class Kaspersky : AntiVirus
{
private:
	Kaspersky() { safety = 40;}
public:
	void print();

	static Kaspersky *Instance();
};

