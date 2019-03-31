//DeQueu costly version
#include "ArrayStack.h"
using namespace std;

#ifndef AQUEU_H
#define AQUEU_H

template <class X>
class AQueu
{
private:
  ArrayStack<X>* stack0;
  ArrayStack<X>* stack1;

public:
  void EnQueu(X value)
  {
    this->stack0->Push(value);
  }

  X DeQueu()
  {
    while (this->stack0->Head() > 0)
    {
      this->stack1->Push(this->stack0->Pop());
    }

    return stack1->Pop();
  }

  //Wanted to add a peeq method, stack overflows everytime, kinda wierd.

  AQueu()
  {
    this->stack0 = new ArrayStack<X>(10);
    this->stack1 = new ArrayStack<X>(10);
  }

  AQueu(int size)
  {
    this->stack0 = new ArrayStack<X>(size);
    this->stack1 = new ArrayStack<X>(size);
  }
};

#endif
