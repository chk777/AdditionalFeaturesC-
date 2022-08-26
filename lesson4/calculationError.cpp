#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
used namespace std;

double countError(const vector<double>& input)
{
	double sum = accumulate(input.begin(), input.end(), 0.f, [](double currentSum, double const& value) {return currentSum + pow((value - (int)value), 2); });
	return sum;
}
