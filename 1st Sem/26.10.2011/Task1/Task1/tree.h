#pragma once

struct Tree;

bool existsTree(Tree* t, int val);
Tree* addTree(Tree *&t, int val);
int deleteMinTree(Tree *&t);
void deleteFromTree(Tree *&t, int val);
void preorderTree(Tree *t);
void postorderTree(Tree *t);
void symmorderTree(Tree *t);
void resymmorderTree(Tree *t);
void actionTree(Tree *t);
void deleteTree(Tree *t);

struct Tree
{
	int value;
	Tree *leftNode;
    Tree *rightNode;

	Tree();
	Tree(int val);


	bool exists(int val);
	Tree* add(int val);
	Tree* deleteVal(int val);
	void postOrder();
	void preOrder();
	void symmOrder();
	void resymmOrder();
};
