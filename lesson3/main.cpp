#include <iostream>
#include <list>
#include "averageSum.h"
#include "matrix.h"
#include "costIterator.h"
used namespace std;



int main()
{
	//Task 1
	cout << "Task 1:\n";
	list<double> example = { 1.2, 5.3, 4.2, 6.2, 1.5 };
	printList(example);
	addAverage(example);
	printList(example);

	//Task 2
	cout << "\nTask 2:" << endl;
	matrix matr;
	matr.randomFill();
	matr.print();
	cout << "Determinant is: " << calculateDeterminant(matr) << endl;

	//Task 3
	cout << "\nTask 3:\n";
	myContainer arr;
	for (auto it : arr)
	{
		it = 0;
		cout << it << " ";
	}
}
