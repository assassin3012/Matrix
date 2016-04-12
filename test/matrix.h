#pragma once
#ifndef matrix_h
#define matrix_h
#include <iostream>
#include <string>
#include "matrixexception.h"
using namespace std;

template <typename T>
class Matrix;

/*template <typename T>
std::ostream &operator << (std::ostream &out, const Matrix<T> &temp)
{
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.m; j++)
		{
			out << temp.matrix[i][j] << " ";
		}
		out << endl;
	}
	return out;
}
template <typename T>
std::istream &operator >> (std::istream &input, Matrix<T> &matr)
{
    for (int i = 0; i < matr.n; i++) 
    {
        for (int j = 0; j < matr.m; j++) 
        {
            if (!(input >> matr.matrix[i][j]))
            {
                throw "Error matrix fill";
            }
        }
    }
    return input;
}*/
template <typename T>
class Matrix
{
public:
	Matrix<T>() :n(0), m(0), matrix(nullptr) {};
	Matrix(unsigned int rows, unsigned int columns);
	Matrix(const Matrix &copy);
	~Matrix<T>();
	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix &operator = (const Matrix&);
	bool operator == (const Matrix&);
	T* operator [] (unsigned int);
	unsigned int Rows() const;
	unsigned int Columns() const;
	friend std::ostream &operator << <>(std::ostream &out, const Matrix<T> &temp)
	{
		for (int i = 0; i < temp.n; i++)
		{
			for (int j = 0; j < temp.m; j++)
			{
				out << temp.matrix[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}
	friend std::istream &operator >> <>(std::istream &input, Matrix<T> &matr)
	{
		for (int i = 0; i < matr.n; i++) 
		{
        		for (int j = 0; j < matr.m; j++) 
        		{
        			try {
            				if (!(input >> matr.matrix[i][j]))
            				{
                				throw FillException();
            				}
        			}
        			catch (...) {
        				throw FillException();
        			}
        		}
	 	}
	 	return input;
	};
private:
	T **matrix;
	unsigned int n;	// ñòðîê
	unsigned int m;	// ñòîëáöîâ
};
#include "matrix.cpp"
#endif
