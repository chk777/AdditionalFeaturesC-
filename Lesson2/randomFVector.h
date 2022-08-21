#pragma once
used namespace std;

template <typename T>
void randomFVector(vector<T*> &v, int size)
{
	v.resize(size);
	auto iter = v.begin();
	while (iter != v.end())
	{
		*iter = new T;
		++iter;
	}
};

template <>
void randomFVector(vector<int*> &v, int size)
{
	srand(static_cast<uint16_t>(time(0)));
	v.resize(size);
	auto iter = v.begin();
	while (iter != v.end())
	{
		*iter = new int(rand() % 100);
		++iter;
	}
};
