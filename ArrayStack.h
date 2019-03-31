#include "Array.h"

using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

class ArrayStackException : public exception {};
class ArrayStackOverflow : public ArrayStackException {} StackOverflow;
class ArrayStackUnderflow : public ArrayStackException {} StackUnderflow;

template <class X>
class ArrayStack
{
private:
  Array<X>* stack;
  int head;

public:
  void Push(X value)
  {
    try
    {
      if (stack->Size() == head) throw StackOverflow;
      (*stack)[this->head] = value;
    }
    catch (ArrayStackOverflow e) {cout << "StackOverflow" << endl;}
    head++;
  }

  X Pop()
  {
    try
    {
      if (head < 1) throw StackUnderflow;
      head--;
      return (*stack)[this->head];
    }
    catch (ArrayStackUnderflow e) {cout << "StackUnderflow" << endl;}

  }

  X Peek()
  {
    try
    {
    if (head < 1) throw StackUnderflow;
    return (*stack)[this->head - 1];
    }
    catch (ArrayStackUnderflow e) {cout << "StackUnderflow" << endl;}
  }

  int Head()
  {
    return this->head;
  }

  ArrayStack()
  {
    this->stack = new Array<X>(10);
    this->head = 0;
  }
  ArrayStack(int size)
  {
    this->stack = new Array<X>(size);
    this->head = 0;
  }
};
#endif
