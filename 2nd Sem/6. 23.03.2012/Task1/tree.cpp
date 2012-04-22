#include "tree.h"

int NumLeaf::calc()
{
    return val;
}
 void NumLeaf::print()
 {
     cout << val << " ";
 }

 int OperationLeaf::calc()
 {
     int a = left->calc();
     int b = right->calc();

     switch (op)
     {
     case '+':
         return a + b;
     case '-':
         return a - b;
     case '*':
         return a * b;
     case '/':
         return a / b;
     }

 }
  void OperationLeaf::print()
  {
      cout << "( " << op << " ";
      left->print();
      right->print();
      cout << ") ";
  }

  void OperationLeaf::build(string &s)
  {
      s.erase(0, 1); // remove '('
      op = s[0];
      s.erase(0, 1); // remove op
      OperationLeaf *tmp;
      if (s[0] == '(')
      {
          tmp = new OperationLeaf();
          tmp->build(s);
          left = tmp;
      }
      else
          left = new NumLeaf(s[0] - '0');
      s.erase(0, 1); // remove num or ')'

      if (s[0] == '(')
      {
          tmp = new OperationLeaf();
          tmp->build(s);
          right = tmp;
      }
      else
          right = new NumLeaf(s[0] - '0');
      s.erase(0, 1);

  }
