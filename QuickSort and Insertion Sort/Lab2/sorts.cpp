#include "sorts.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void spit(vector<int> *tmp) {
	for (int i = 0; i < (int)tmp->size(); i++) {
		cout << tmp->at(i) << ' ';
	}
}

void insertionSort(vector<int> & a, int n) {
	//note: i = 1
	for (int i = 1; i < n; i++) { 
		//make a copy of a[i]
		int j, temp = a[i]; 
		//starting moving left
		for (j = i - 1; j >= 0; j--) { 
			if (a[j] > temp)
				//inversion detected; move a[j] to the right
				a[j + 1] = a[j]; 
			else
				//index j is where temp belongs
				break; 
		}
		a[j+1] = temp;
	}
}

int partition(vector<int> & a, int left, int right, int pivotIndex) {
	int pivotValue = a[pivotIndex];
	swap(a[pivotIndex], a[right]);
	//partition the array. upon finding an element smaller than pivot,
	//swap it to the next position in the store.
	int store = left;
	for (int i = left; i < right; i++) {
		if (a[i] < pivotValue) {
			swap(a[store], a[i]);
			store++;
		}
	}
	//swap pivot to its final position.
	swap(a[right], a[store]); 
	return store;
}

int median(vector<int> & a, int start, int end) {
	int left = a[start];
	int right = a[end];
	int mid = a[(start + end)/2];
	//Clever median calculation I found online
	if ((left - mid) * (right - left) >= 0) {
		return start;
	}
	else if ((mid - left) * (right - mid) >= 0) {
		return (start+end)/2;
	}
	else {
		return end;	
	}
}

void quickSort(vector<int> &A, int left, int right) {
	if (left == right) return;	
	int middle = ((left + right) / 2);
	int midpoint = partition(A, left, right, median(A, left, right));
	//swap(A[left], A[midpoint]);
	//have 2 checks
	//confirm that the beginning index is less than the final index
	if (left < midpoint) { quickSort(A, left, midpoint - 1); }
	//Then confirm that the ending index is > beginning index
	if (right > midpoint) { quickSort(A, midpoint + 1, right); }	
}
