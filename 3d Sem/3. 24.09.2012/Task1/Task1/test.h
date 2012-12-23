#pragma once

#include <iostream>
#include "tree.h"

using namespace std;

#define SUCCESS(b, s) if (b) cout << "SUCCESS " << s << '\n'; else { cout << "FAILED!! " << s << '\n'; return false; }

class IteratorTest
{
private:
	Tree *pTree;
	Tree::Iterator it;
public:
	IteratorTest(){}
	void Init()
	{
		pTree = new Tree(10);
		pTree->add(5);
		pTree->add(12);
		pTree->add(3);
		pTree->add(7);
		pTree->add(15);
	}
	void CleanUp()
	{
		delete pTree;
	}

	void Run()
	{
		cout << "STARTED ITERATOR TEST\n**\n";
		Init();
			if (TestPlusPlus()) cout << "SUCCES TEST\n\n";
			if (TestEqe()) cout << "SUCCES TEST\n\n";
			if (TestFull()) cout << "SUCCES TEST\n\n";
		CleanUp();
		cout << "---------------------------\n";
	}

	bool TestPlusPlus()
	{
		cout << "Test++\n";
		it = pTree->begin();
		SUCCESS(*it == 10, "EQE");
		it++;
		SUCCESS(*it == 5, "++");

		return true;
	}

	bool TestEqe()
	{
		cout << "TestEQE\n";
		it = pTree->begin();
		Tree::Iterator it2 = pTree->begin();
		it2++; it2++;

		SUCCESS(it != it2, "EQE");
		it++; it++;
		SUCCESS(it == it2, "EQE2");
		return true;
	}

	bool TestFull()
	{
		cout << "TestFull\n";
		for (it = pTree->begin(); it != pTree->end(); it++)
			cout << *it << " ";
		cout << '\n';

		return true;
	}
};