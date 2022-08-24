#include <iostream>
#include <vector>
used namespace std;

class matrix
{
private:
	size_t m_size;
	vector<int*> m_values;
public:
	matrix(int matrixSize);

	int getSize() { return m_size; }
	int& operator()(int i, int j);
	void randomFill(int valueRange);
	void print();
	void addValue(int value);
};

matrix::matrix(int matrixSize)
	: m_size(matrixSize)
{
	m_values.reserve(m_size * m_size);
}

int& matrix::operator()(int i, int j)
{
	return *m_values[i * m_size + j];
}

void matrix::randomFill(int valueRange)
{
	srand((unsigned int)time(0));
	for (size_t index = 0; index < m_size * m_size; ++index)
	{
		m_values.push_back(new int(rand() % valueRange));
	}
}

void matrix::print()
{
	int index = 0;
	for (auto value : m_values)
	{
		cout << *value << " ";
		if (*value < 10) cout << " ";
		++index;
		if (index % m_size == 0) cout << endl;
	}

}

void matrix::addValue(int value)
{
	if (m_values.size() < m_size * m_size)
	{
		m_values.push_back(new int(value));
	}
}

int calculateDeterminant(matrix& inputMatrix)
{
	if (inputMatrix.getSize() == 2)
	{
		return (inputMatrix(0, 0) * inputMatrix(1, 1) - inputMatrix(0, 1) * inputMatrix(1, 0));
	}
	else
	{
		int determinant = 0;
		for (int parentMatrixColumnIndex = 0; parentMatrixColumnIndex < inputMatrix.getSize(); ++parentMatrixColumnIndex)
		{
			int sign = 1;
			if (parentMatrixColumnIndex % 2 == 1) { sign = -1; }
			Matrix minorMatrix(inputMatrix.getSize() - 1);
			for (int row = 1; row < inputMatrix.getSize(); ++row)
			{
				for (int column = 0; column < inputMatrix.getSize(); ++column)
				{
					if (column != parentMatrixColumnIndex) minorMatrix.addValue(inputMatrix(row, column));
				}
			}
			determinant += sign * (inputMatrix(0, parentMatrixColumnIndex)*calculateDeterminant(minorMatrix));
		}
		return determinant;
	}
}
