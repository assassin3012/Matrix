#pragma once
#ifndef matrix_h
#define matrix_h

#include <iostream>
#include <fstream>
#include <string>
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
	Matrix<T>(int rows, int columns);
	Matrix<T>(const Matrix &copy);
	~Matrix();
	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix &operator = (const Matrix&);
	bool operator == (const Matrix&);
	T* operator [] (int);
	int Rows() const;
	int Columns() const;
	friend ostream &operator << (ostream &out, const Matrix<T> &temp);
	friend istream &operator >> (istream &input, Matrix<T> &matr);
private:
	T **matrix;
	int n;	// ñòðîê
	int m;	// ñòîëáöîâ
};

#endif
