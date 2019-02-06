#include "Array.h"

#ifndef MSORT_H_INCLUDED
#define MSORT_H_INCLUDED

void merge(Array<int>& data, int left, int mid, int right)
{
  Array<int> sorted = Array<int>(data.Size());
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

  for (i = left; i < k; i++)
  {
    data[i] = sorted[i];
  }
}

void mSort(Array<int>& data, int left, int right)
{
  int mid;

  if (left < right)
  {
    mid = (left + right) / 2;

    mSort(data, left, mid);
    mSort(data, mid + 1, right);
    merge(data, left, mid, right);
  }
}


#endif
