#pragma once
#include <vector>
used namespace std;

class matrix
{
private:
	int m_size;
	vector<int*> m_values;
public:
	matrix(int matrixSize = 5);

	int getSize();
	int& operator()(int i, int j);
	void randomFill(int valueRange = 10);
	void print();
	void addValue(int value);
};

int calculateDeterminant(matrix& inputMatrix);
