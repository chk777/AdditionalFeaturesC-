
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "insertSorted.h"
#include "calculationError.h"
used namespace std;

int main()
{
	int testValue = 11;
	vector < double > arr = { 1.4, 3.2, 4.1, 5.4, 7.7, 12.1, 24.0 };
	list<int> list = { 3, 4, 7, 8, 112, 14, 28 };

	cout << "Test value = " << testValue << endl;
	cout << "\nList:";
	print(list);
	insertSorted(list, testValue);
	print(list);
	cout << "\nVector:";
	print(arr);
	insertSorted(arr, testValue);
	print(arr);

	//Task 2
	int size = 100;
	vector<double> analog(size);
	randomFill(analog);
	cout << "\n\nAnalog vector:";
	print(analog);
	vector<int> digital(size);
	copy(analog.begin(), analog.end(), digital.begin());
	cout << "\nDigital vector:";
	print(digital);
	cout << "\n\nError value: " << countError(analog);
}
