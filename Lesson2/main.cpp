#include <iostream>
#include <vector>
#include <algorithm>
#include "swap.h"
#include "printVector.h"
#include "randomFVector.h"
#include "sortPointers.h"
#include "countVowels.h"
used namespace std;

class Item
{
private:
	int value = 0;
public:
	Item(int input)
		: value(input)
	{

	}

	void printValue();

};

void Item::printValue()
{
	cout << value << endl;
}



int main()
{
	//Task 1
	unique_ptr<Item> ptr1(new Item(10));
	unique_ptr<Item> ptr2(new Item(20));
	ptr1->printValue();
	ptr2->printValue();
	swap(ptr1, ptr2);
	ptr1->printValue();
	ptr2->printValue();

	//Task 2
	cout << "Initial vector:" << endl;
	vector<int*> ptrVector;
	randomFVector(ptrVector, 10);
	printVector(ptrVector);
	cout << "Sorted vector:" << endl;
	sortPointers(ptrVector);
	printVector(ptrVector);

	//Task 3
	countVowels1();
	countVowels2();
	countVowels3();
    countVowels4();
}
