#include <iostream>

using namespace std;

#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

class ArrayException : public exception {};

class ArrayIndexException : public ArrayException {} IndexException; // throw IndexException catch ArrayIndexException

class ArrayAllocationException : public ArrayException {} AllocationException;

template <class X>
class Array

{

private:

  int size;// default is 10
  X* data;

public:

  int Size()
  {
    return this->size;
  }

  int Index(X item)
  {
    for (int i = 0; i < this->size; i++)
    {
      if (this->data[i] == item)
      {
        return i;
      }
    }
  }

  bool Contains(X item)// get this to work
  {
    for (int i = 0; i < this->size; i++)
    {
      if (item == this->data[i])
      {
        return true;
      }
    }
    return false;
  }

  X& operator[](int index)
  {
    try
    {
      if (index < 0 || index > this->size - 1) throw IndexException;

      return this->data[index];
    }
    catch (ArrayIndexException e)
    {
      cout << "IndexException" << endl;
    }
  }

  friend ostream& operator<<(ostream& stream, Array& array)
  {
    stream << "[";

    for(int i = 0; i < array.size; i++)
    {
      stream << array[i];

      if (i < array.size - 1)
      {
        stream << ", ";
      }
    }

    stream << "]";

    return stream;
  }

  void operator=(Array& array)
  {
    if (this->size < array.Size())
    {
      delete[] this->data;
      this->data = new X[array.Size()];
    }
    size = array.Size();
    for (int i = 0; i < size; i++)
    {
      this->data[i] = array[i];
    }

  }

  Array()
  {
    try
    {
      this->size = 10;
      this->data = new X[this->size];

      if (this->data == NULL) throw AllocationException;
    }
    catch (ArrayAllocationException e)
    {
      cout << "AllocationException" << endl;
    }
  }

  Array(int size)
  {
    try
    {

      this->size = size;
      this->data = new X[this->size];

      if (this->data == NULL) throw AllocationException;
    }
    catch (ArrayAllocationException e)
    {
      cout << "AllocationException" << endl;
    }
  }

  Array(int size, X zero)
  {
    try
    {

      this->size = size;
      this->data = new X[this->size];

    if (this->data == NULL) throw AllocationException;
    }
    catch (ArrayAllocationException e)
    {
      cout << "AllocationException" << endl;
    }
    for (int i = 0; i < this->size; i++)
    {
      this->data[i] = zero;
    }
  }

 ~Array()
 {
   if (this->data != NULL)
   {
     delete[] this->data;
     this->data = NULL;
   }

 }

};
#endif
