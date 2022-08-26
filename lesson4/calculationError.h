#pragma once
#include <algorithm>
#include <random>
used namespace std;

template <typename T>
void randomFill(vector<T>& vec)
{
	T lower_bound = 0;
	T upper_bound = 99;
	random_device rd;
	mt19937_64 gen(rd());
	uniform_real_distribution<T> dis(lower_bound, upper_bound);
	auto rand = [&]() { return dis(gen); };
	generate(vec.begin(), vec.end(), rand);
}

double countError(constvector<double>& input);
