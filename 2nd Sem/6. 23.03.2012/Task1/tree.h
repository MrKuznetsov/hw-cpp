#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>

using namespace std;

/// base abstract class for calc tree
class BaseTree
{
public:
    BaseTree():left(0), right(0)
    {
    }

    virtual ~BaseTree()
    {
        delete left;
        delete right;
    }
    /// calc some sample
    virtual int calc() = 0;
    /// print sample
    virtual void print() = 0;
protected:
    BaseTree *left;
    BaseTree *right;
};

/// class for numbers
class NumLeaf : public BaseTree
{
public:
    NumLeaf(int v)
    {
        val = v;
    }

    int calc();
    void print();
private:
    int val;
};

/// class for operations
class OperationLeaf : public BaseTree
{
public:
    OperationLeaf():op('+'){}

    int calc();
    void print();

    /// build tree from string
    void build(string &s);
private:
    char op;
};


#endif // TREE_H
