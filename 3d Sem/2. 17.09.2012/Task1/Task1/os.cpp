#include "os.h"

void OperatingSystem::printOS() 
{
	std::cout << "Os: ";
}

void OperatingSystem::print()
{
	printOS();
	std::cout << '\n';
}

int OperatingSystem::getChance()
{
	return chance;
}

OperatingSystem *OperatingSystem::Instance()
{
	static OperatingSystem inst;
	return &inst;
}

void WindowsXP::printOS() 
{
	OperatingSystem::printOS();
	std::cout << "WindowsXP";
}

WindowsXP *WindowsXP::Instance()
{
	static WindowsXP inst;
	return &inst;
}

void Windows7::printOS() 
{
	OperatingSystem::printOS();
	std::cout << "Windows7";
}

Windows7 *Windows7::Instance()
{
	static Windows7 inst;
	return &inst;
}

void Linux::printOS() 
{
	OperatingSystem::printOS();
	std::cout << "Linux";
}

Linux *Linux::Instance()
{
	static Linux inst;
	return &inst;
}

void Mac::printOS() 
{
	OperatingSystem::printOS();
	std::cout << "Mac";
}

Mac *Mac::Instance()
{
	static Mac inst;
	return &inst;
}