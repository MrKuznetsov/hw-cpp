#pragma once

#include <stdio.h>
#include <tchar.h>
#include <stack>


class Tree
{
private:
	int value;
	Tree *leftNode;
    Tree *rightNode;
protected:
	void deleteFromTree(Tree *&t, int val);
	int deleteMinTree(Tree *&t);
public:

	class Iterator;

	Tree();
	Tree(int val);
	virtual ~Tree();

	bool exists(int val);
	Tree* add(int val);
	Tree* deleteVal(int val);

	Tree *left();
	Tree *right();

	int &val();

	Iterator begin();
	static Iterator end();

	friend Iterator;
};

class Tree::Iterator
{
private:
	Tree* pTree;
	std::stack<Tree *> stack;
public:
	Iterator();
	Iterator(Tree* tree);
	Iterator &operator++ ();
	Iterator &operator= (const Tree::Iterator &i);
    bool operator== (const Tree::Iterator &i);
	bool operator!= (const Tree::Iterator &i);
    int &operator* ();
};

