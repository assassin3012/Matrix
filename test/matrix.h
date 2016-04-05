#pragma once
#ifndef matrix_h
#define matrix_h
#include <iostream>
using namespace std;

template <typename T>
class Matrix;

template <class T>
ostream &operator << (ostream &out, const Matrix<T> &);

template <class T>
istream &operator >> (istream &input, Matrix<T> &);

template <typename T>
class Matrix
{
public:
	Matrix<T>() :n(0), m(0), matrix(nullptr) {}
	Matrix(int rows, int columns);
	Matrix(const Matrix &copy);
	~Matrix<T>();
	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix &operator = (const Matrix&);
	bool operator == (const Matrix&);
	T* operator [] (int);
	int Rows() const;
	int Columns() const;
	friend std::ostream &operator << (std::ostream &out, const Matrix<T> &temp);
	friend std::istream &operator >> (std::istream &input, Matrix<T> &matr);
private:
	T **matrix;
	int n;	// ñòðîê
	int m;	// ñòîëáöîâ
};
#include "matrix.cpp"
#endif
