#include "sorts.h"
#include <chrono>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using namespace chrono;

/*This program sorts a text file of integers. Actually with a bit more implementaiton, we
could easily sort any comparable value.In addition, it also times the speed of your algorhithem,
however I haven't implemented it in a manner that lets you compare them sdie by side. 
So far I just lop the time tests in the sorts.cpp for multiple samples.
*/
int main() {
	vector<int> original;
	cout << "What is the name of the file you would like to sort? " << endl;
	string uInput;
	cin >> uInput;
	ifstream file(uInput);
	string line;

	//Yes I know this causes problems, I accounted for it.
	for (int i = 0; i < 10; i++) {
		while (getline(file, line)) {
			stringstream lineStream(line);
			int value;
			while (lineStream >> value) {
				original.push_back(value);
			}
		}
		//This block times and sorts the file we inputted.
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			//Manually choose between quicksort and insertion sort.
			//quickSort(original, 0, original.size() - 1);
			insertionSort(original, original.size()-1);//sorts and prints
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(t2 - t1).count();
			cout << "Time : " << duration << endl;
	}
	cin.get();				//Serves as a pause
	cin.get();
}
