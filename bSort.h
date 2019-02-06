#include "Array.h"

#ifndef BSORT_H_INCLUDED
#define BSORT_H_INCLUDED

void bSort(Array<int>& array)
{

  bool swapped = false;

  for(int j = 0; j < array.Size(); j++)
  {
    for(int i = 0; i < array.Size() - j; i++)
    {
      swapped = false;
      if (array[i] > array[i + 1])
      {
        array[i+1] = array[i];
        array[i] = array[i+1];
        swapped = true;
      }
    }
    if (swapped == false)
    {
      break;
    }
  }
}

#endif
