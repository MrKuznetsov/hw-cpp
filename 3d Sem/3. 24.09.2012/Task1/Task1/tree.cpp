#include "tree.h"

Tree::Tree()
{
	value = 0;
	leftNode = NULL;
	rightNode = NULL;
}

Tree::Tree(int val)
{
	value = val;
	leftNode = NULL;
	rightNode = NULL;
}

Tree::~Tree()
{
	delete leftNode;
	delete rightNode;
}

Tree* Tree::add(int val)
{
	if (value == val)
		return this;
	else if (value > val)
	{
		if (leftNode)
			return leftNode->add(val);
		else
			return leftNode = new Tree(val);
	}
	else
	{
		if (rightNode)
			return rightNode->add(val);
		else
			return rightNode = new Tree(val);
	}
}
Tree* Tree::deleteVal(int val)
{
	Tree *tmp = this;
	deleteFromTree(tmp, val);
	return tmp;
}

void Tree::deleteFromTree(Tree *&t, int val)
{
	if (!t) return;
	if (t->value > val)
		deleteFromTree(t->leftNode, val);
	else if(t->value < val)
		deleteFromTree(t->rightNode, val);
	else if (!t->leftNode && !t->rightNode)
	{
		delete t;
		t = NULL;
	}
	else if (!t->leftNode)
	{
		Tree *tmp = t;
		t = t->rightNode;
		delete tmp;
	}
	else if (!t->rightNode)
	{
		Tree *tmp = t;
		t = t->leftNode;
		delete tmp;
	}
	else
		t->value = deleteMinTree(t->rightNode);
}

int Tree::deleteMinTree(Tree *&t)
{
	if (!t->leftNode)
	{
		int res = t->value;
		Tree *tmp = t;
		t = t->rightNode;
		delete tmp;
		return res;
	}
	else
		return deleteMinTree(t->leftNode);
}

Tree *Tree::left()
{
	return leftNode;
}

Tree *Tree::right()
{
	return rightNode;
}

int &Tree::val()
{
	return value;
}

bool Tree::exists(int val)
{
	if (value == val)
		return true;

	if (value > val && leftNode)
		return leftNode->exists(val);
	if (rightNode)
		return rightNode->exists(val);

	return false;
}

Tree::Iterator Tree::begin()
{
	return Tree::Iterator(this);
}

Tree::Iterator Tree::end()
{
	static Tree::Iterator it(NULL);
	return it;
}


Tree::Iterator::Iterator(Tree* tree)
{
	pTree = tree;
	if (pTree != NULL)
	{
		stack.push(pTree->rightNode);
		stack.push(pTree->leftNode);
	}
}

Tree::Iterator::Iterator()
{
	pTree = NULL;
}



Tree::Iterator &Tree::Iterator::operator++ ()
{
	if (stack.size() == 0)
		pTree = NULL;
	else
	{
		pTree = stack.top();
		stack.pop();
	}

	if (pTree == NULL)
		return *this;

	if(pTree->rightNode)
		stack.push(pTree->rightNode);
	if (pTree->leftNode)
		stack.push(pTree->leftNode);


	return *this;
}

Tree::Iterator &Tree::Iterator::operator= (const Tree::Iterator &i)
{
	pTree = i.pTree;
	std::stack<Tree *> tmp(i.stack);
	stack = tmp;
	//stack.swap(tmp);

	return *this;
}

bool Tree::Iterator::operator== (const Tree::Iterator &i)
{
	return (i.pTree == pTree);
}

bool Tree::Iterator::operator!= (const Tree::Iterator &i)
{
	return (i.pTree != pTree);
}

int &Tree::Iterator::operator* ()
{
	int tmp = 0;
	if (pTree == NULL)
		return tmp;
	return pTree->value;
}
