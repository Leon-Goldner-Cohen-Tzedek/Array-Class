# Array-Class
An array wrapper for C++

binSearch.h is a binary search function that works with Array.h, just include them in the same main.cpp and they should work together.

For example:

Array x = Array(100, 16);// makes an array with 100 indexes set to 16

cout << binSearch(3, x, 0, x.Size() - 1) << endl; // searches for 3 in the array and prints 0


