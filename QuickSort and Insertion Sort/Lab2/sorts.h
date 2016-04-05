#ifndef __SORTS_H
#define __SORTS_H
#include <vector>
//Outputs(spits out/cout's) vector contents
void spit(std::vector<int> * tmp);

//Returns the median of function. Maybe I need to pass in vector as a pointer? 
int median(std::vector<int> & a, int left, int right);

//Insertion sort
void insertionSort(std::vector<int> & tmp, int a);

//Used to partition the vector before quicksorting. Pivot index is calculated recursively
int partition(std::vector<int> & a, int left, int right, int pivotIndex);

//Quicksorts a vector, uses recursion.
void quickSort(std::vector<int> &A, int left, int right);

#endif