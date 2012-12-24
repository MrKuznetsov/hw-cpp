#pragma once

#include "antiVirus.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

class OperatingSystem
{
protected:
	int chance;
	OperatingSystem() : chance(0){}
public:
	virtual void printOS();
	void print();
	int getChance();

	static OperatingSystem *Instance();
};

class WindowsXP : OperatingSystem
{
protected:
	WindowsXP() : OperatingSystem()
	{
		chance = 20;
	}
public:
	void printOS();

	static WindowsXP *Instance();
};

class Windows7 : OperatingSystem
{
protected:
	Windows7() : OperatingSystem() 
	{
		chance = 30;
	}

public:
	void printOS() ;

	static Windows7 *Instance();
};

class Linux : OperatingSystem
{
protected:
	Linux() : OperatingSystem() 
	{
		chance = 25;
	}
public:
	void printOS() ;

	static Linux *Instance();
};

class Mac : OperatingSystem
{
protected:
	Mac() : OperatingSystem() 
	{
		chance = 30;
	}

public:
	void printOS();

	static Mac *Instance();
};