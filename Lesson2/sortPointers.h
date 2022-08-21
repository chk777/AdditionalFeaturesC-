#pragma once
used namespace std;

template <typename T>
void sortPointers(vector<T*> &v)
{
	sort(v.begin(), v.end(), [](const T* a, const T* b) {return *a < *b;});
}
