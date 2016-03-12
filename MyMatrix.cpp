// MyMatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}

class Matrix
{
public:
	Matrix() :n(0), m(0), matrix(nullptr) {}
	Matrix(int rows, int columns);
	Matrix(const Matrix& copy);
	~Matrix();
	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix &operator = (const Matrix&);
	bool FillFromFile(const  std::string &filePath);
	int* operator [] (int);
	int Rows() const;
	int Columns() const;
	int Maxelement() const;
	int Minelement() const;
	void Fill();
	friend ostream &operator << (ostream &cout,const Matrix &temp);
private:
	int **matrix;
	int n;	// строк
	int m;	// столбцов
};

Matrix::Matrix(int rows, int columns):n(rows), m(columns)
{
	matrix = new int*[n];
	for (int i = 0; i<n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j<m; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& copy):n(copy.n), m(copy.m)
{
	matrix = new int*[n];
	for (int i = 0; i<n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j<m; j++)
		{
			matrix[i][j] = copy.matrix[i][j];
		}
	}
}
Matrix::~Matrix()
{
	if (matrix != nullptr)
	{
		for (int i = 0; i<n; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

Matrix Matrix::operator + (const Matrix &matr)
{
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result.matrix[i][j] = matrix[i][j] + matr.matrix[i][j];
		}
	}
	return result;
}
Matrix Matrix::operator - (const Matrix &matr)
{
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result.matrix[i][j] = matrix[i][j] - matr.matrix[i][j];
		}
	}
	return result;
}
Matrix Matrix::operator * (const Matrix &matr)
{
	Matrix result(n, matr.m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < matr.m; j++)
		{
			int value = 0;
			for (int k = 0; k < m; k++)
			{
				value += matrix[i][k] * matr.matrix[k][j];
			}
			result.matrix[i][j] = value;
		}
	}
	return result;
}
Matrix &Matrix::operator = (const Matrix &matr)
{
	if (this != &matr)
	{
		if (matrix != nullptr)
		{
			for (int i = 0; i<n; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		n = matr.n;
		m = matr.m;
		matrix = new int*[n];
		for (int i = 0; i<n; i++)
		{
			matrix[i] = new int[m];
			for (int j = 0; j<m; j++)
			{
				matrix[i][j] = matr.matrix[i][j];
			}
		}
	}
	return *this;
}
bool Matrix::FillFromFile(const std::string &filePath)
{
	ifstream input;
	input.open(filePath);
	bool isSucess = true;
	if (input.is_open())
	{
		if (matrix != nullptr)
		{
			for (int i = 0; i < n; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		int rows, columns;
		input >> rows >> columns;
		n = rows;
		m = columns;
		matrix = new int*[n];
		for (int i = 0; i < n; i++)
		{
			matrix[i] = new int[m];
			for (int j = 0; j < m; j++)
			{
				input >> matrix[i][j];
			}
		}
	}
	else
	{
		isSucess = false;
	}
	input.close();
	return isSucess;
}
int* Matrix::operator [] (int index)
{
	if (index <= this->n)
	{
		return this->matrix[index];
	}
	else
	{
		return nullptr;
	}
}
int Matrix::Rows() const
{
	return n;
}
int Matrix::Columns() const
{
	return m;
}
int Matrix::Maxelement() const
{
	int maxelement = matrix[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			maxelement = max(maxelement, matrix[i][j]);
		}
	}
	return maxelement;
}
int Matrix::Minelement() const
{
	int minelement = matrix[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			minelement = min(minelement, matrix[i][j]);
		}
	}
	return minelement;
}
void Matrix::Fill()
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cout << "Enter [" << i << "][" << j << "] element of Matrix: ";
			cin >> matrix[i][j];
		}
	}
}
ostream &operator << (ostream &os,const Matrix &temp)
{
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.m; j++)
		{
			os << temp.matrix[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

int main()
{
	string str1("text.txt");
	Matrix n;
	cout << n.FillFromFile(str1);
	cout << n;
	Matrix m1(2, 3);
	m1.Fill();
	Matrix m2(3, 4);
	m2.Fill();
	Matrix m;
	m = m1*m2;
	cout << m;
	system("pause");
	return 0;
}

