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
public:
	OperatingSystem()
	{
		chance = 0;
	}

	virtual void printOS() {std::cout << "Os: ";}

	void print()
	{
		printOS();
		std::cout << '\n';
	}

	int getChance()
	{
		return chance;
	}

	static OperatingSystem *Instance()
	{
		static OperatingSystem inst;
		return &inst;
	}
};

class WindowsXP : OperatingSystem
{
public:
	WindowsXP() : OperatingSystem() 
	{
		chance = 20;
	}

	void printOS() 
	{
		OperatingSystem::printOS();
		std::cout << "WindowsXP";
	}

	static WindowsXP *Instance()
	{
		static WindowsXP inst;
		return &inst;
	}
};

class Windows7 : OperatingSystem
{
public:
	Windows7() : OperatingSystem() 
	{
		chance = 30;
	}

	void printOS() 
	{
		OperatingSystem::printOS();
		std::cout << "Windows7";
	}

	static Windows7 *Instance()
	{
		static Windows7 inst;
		return &inst;
	}
};

class Linux : OperatingSystem
{
public:
	Linux() : OperatingSystem() 
	{
		chance = 25;
	}

	void printOS() 
	{
		OperatingSystem::printOS();
		std::cout << "Linux";
	}

	static Linux *Instance()
	{
		static Linux inst;
		return &inst;
	}
};

class Mac : OperatingSystem
{
public:
	Mac() : OperatingSystem() 
	{
		chance = 30;
	}

	void printOS() 
	{
		OperatingSystem::printOS();
		std::cout << "Mac";
	}

	static Mac *Instance()
	{
		static Mac inst;
		return &inst;
	}
};