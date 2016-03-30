#pragma once
#ifndef matrix_h
#define matrix_h

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
	bool operator == (const Matrix&);
	bool FillFromFile(char *filePath);
	int* operator [] (int);
	int Rows() const;
	int Columns() const;
	void Fill();
	friend ostream &operator << (ostream &cout, const Matrix &temp);
private:
	int **matrix;
	int n;	// ñòðîê
	int m;	// ñòîëáöîâ
};

#endif
