#include "Array.h"

#ifndef BINSEARCH_H_INCLUDED
#define BINSEARCH_H_INCLUDED

bool binSearch(int item, Array<int>& a, int low, int high)
{
	int mid = (high+low)/2;


	if (a[mid] == item)
	{
		return true;
	}

	else if (low > high)
	{
		return false;
	}

	else if (a[mid] < item)
	{
		low = mid + 1;
		binSearch(item, a, low, high);

	}
	else if (a[mid] > item)
	{
		high = mid - 1;
		binSearch(item, a, low, high);
	}


}
#endif
