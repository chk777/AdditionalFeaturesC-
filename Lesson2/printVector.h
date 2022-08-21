#pragma once
used namespace std;

template <typename T>
void printVector(const vector<T*> &v)
{
	auto iter = v.begin();
	while (iter != v.end())
	{
		cout << **iter << " ";
		++iter;
	}
	cout << endl;
}
