#include "Array.h"

#ifndef MSORT_H
#define MSORT_H

void merge(int left, int mid, int right)
{

  sorted(this->size);
  int i = left;
  int j = mid + 1;
  int k = left;

  while (i <= mid && j <= right)
  {
    if (data[i] < data[j]) sorted[k++] = data[i++];
    else sorted[k++] = data[j++];
  }

  while (i <= mid)
  {
    sorted[k++] = data[i++];
  }

  while (j <= right)
  {
    sorted[k++] = data[j++];
  }

  for (i = left; i < k; i++) data[i] = sorted[i];

}

void mSort(int left, int right)
{
  int mid;

  if (left < right)
  {
    mid = (left + right) / 2;

    mSort(left, mid);
    mSort(mid + 1, right);
    mSort(left, mid, right);
  }
}


#endif
