#pragma once

#include <iostream>
#include "tree.h"

using namespace std;

#define SUCCESS(b, s) if (b) cout << "SUCCESS " << s << '\n'; else { cout << "FAILED!! " << s << '\n'; return false; }

class TreeTest
{
private:
	Tree *pTree;
public:
	TreeTest(){}
	void Init()
	{
		pTree = new Tree(10);
	}
	void CleanUp()
	{
		delete pTree;
	}

	void Run()
	{
		cout << "STARTED TREE TEST\n**\n";
		Init();
			if (TestAdd()) cout << "SUCCES TEST\n\n";
			if (TestFind()) cout << "SUCCES TEST\n\n";
			if (TestDelete()) cout << "SUCCES TEST\n\n";
		CleanUp();
		cout << "---------------------------\n";
	}

	bool TestAdd()
	{
		cout << "TestADD\n";
		pTree->add(5);
		SUCCESS(pTree->left()->val() == 5, "add");
		return true;
	}

	bool TestDelete()
	{
		cout << "TestDELETE\n";

		pTree->add(7);
		pTree->add(3);

		pTree->deleteVal(5);
		SUCCESS(!pTree->exists(5), "FIND");
	//	SUCCESS(it == it2, "EQE2");
		return true;
	}

	bool TestFind()
	{
		cout << "TestFind\n";
		pTree->add(12);
		SUCCESS(pTree->exists(12), "FIND");
		
		return true;
	}
};