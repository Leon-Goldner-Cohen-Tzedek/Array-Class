#include "Array.h"

#ifndef BSORT_H_INCLUDED
#define BSORT_H_INCLUDED

void swap(Array<int>& array, int index0, int index1)
{
  int temp = array[index0];
  array[index0] = array[index1];
  array[index1] = temp;
}

void bSort(Array<int>& array)
{

  bool swapped;

  for (int i = 0; i < array.Size() - 1; i++)
  {
    //swapped = true;

    for (int j = 0; j < array.Size() - i - 1; i++)
    {
      if (array[j] > array[j + 1])
      {
        swap(array, j, j + 1);
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
