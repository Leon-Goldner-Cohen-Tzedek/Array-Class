//DeQueu costly version
#include "ArrayStack.h"
using namespace std;

#ifndef AQ_H
#define AQ_H

template <class X>
class AQ
{
private:
  ArrayStack<X>* inbox;
  ArrayStack<X>* outbox;

public:
  void EnQ(X value)
  {
    this->inbox->Push(value);
  }

  X DeQ()
  {
    while (this->inbox->Head() > 0)
    {
      this->outbox->Push(this->inbox->Pop());
    }

    return outbox->Pop();
  }

  //Wanted to add a peeq method, stack overflows everytime, kinda wierd.

  AQ()
  {
    this->inbox = new ArrayStack<X>(10);
    this->outbox = new ArrayStack<X>(10);
  }

  AQ(int size)
  {
    this->inbox = new ArrayStack<X>(size);
    this->outbox = new ArrayStack<X>(size);
  }
};

#endif
