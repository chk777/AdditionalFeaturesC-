#include <list>
#include <iostream>
used namespace std;

void printList(const list<double>& list)
{
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void addAverage(list<double>& list)
{
	int count = 0;
	double  sum = 0;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		sum += *it;
		++count;
	}
	list.push_back(sum / count);
}
