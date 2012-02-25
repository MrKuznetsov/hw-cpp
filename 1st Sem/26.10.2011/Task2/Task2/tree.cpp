#include "stdafx.h"
#include "tree.h"


bool existsTree(Tree *t, int val)
{
	return t->exists(val);
}

Tree* addTree(Tree *&t, int val)
{
	if (t == NULL)
		return t = new Tree(val);
	else if (t->value == val)
		return t;
	else if (t->value > val)
		return addTree(t->leftNode, val);
	else
		return addTree(t->rightNode, val);
}

int deleteMinTree(Tree *&t)
{
	if (!t->leftNode)
	{
		int res = t->value;
		t = t->rightNode;
		return res;
	}
	else
		deleteMinTree(t->leftNode);
}

void deleteFromTree(Tree *&t, int val)
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
		t = t->rightNode;
	else if (!t->rightNode)
		t = t->leftNode;
	else
		t->value = deleteMinTree(t->rightNode);
}
void actionTree(Tree *t)
{
	printf("%c ", t->value);
}

void preorderTree(Tree *t)
{
	if (!t) return;
	actionTree(t);
	preorderTree(t->leftNode);
	preorderTree(t->rightNode);
}

void postorderTree(Tree *t)
{
	if (!t) return;
	postorderTree(t->leftNode);
	postorderTree(t->rightNode);
	actionTree(t);
}

void symmorderTree(Tree *t)
{
	if (!t) return;
	symmorderTree(t->leftNode);
	actionTree(t);
	symmorderTree(t->rightNode);
}
void resymmorderTree(Tree *t)
{
	if (!t) return;
    resymmorderTree(t->rightNode);	
	actionTree(t);
	resymmorderTree(t->leftNode);
}

void deleteTree(Tree *t)
{
	if (!t) return;
	if (t->leftNode)
		deleteTree(t->leftNode);
	if (t->rightNode)
		deleteTree(t->rightNode);
	delete t;
}

//================================================
//==++++++++++++++++ TREE ++++++++++++++++++++++==
//================================================

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

Tree* Tree::add(int val)
{
	if (value == val)
		return this;
	else if (value > val)
		return addTree(leftNode, val);
	else
		return addTree(rightNode, val);
}
Tree* Tree::deleteVal(int val)
{
	Tree *tmp = this;
	deleteFromTree(tmp, val);
	return tmp;
}

bool Tree::exists(int val)
{
	printf("%d", value);
	if (value == val)
		return true;

	if (value > val && leftNode)
		return leftNode->exists(val);
	if (rightNode)
		return rightNode->exists(val);

	return false;
}
void Tree::postOrder()
{
	Tree *tmp = this;
	postorderTree(tmp);
	printf("\n");
};

void Tree::preOrder()
{
	Tree *tmp = this;
	preorderTree(tmp);
	printf("\n");
}

void Tree::symmOrder()
{
	Tree *tmp = this;
	symmorderTree(tmp);
	printf("\n");
}
void Tree::resymmOrder()
{
	Tree *tmp = this;
	resymmorderTree(tmp);
	printf("\n");
}