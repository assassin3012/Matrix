#pragma once
#include <string>
using namespace std;
class MatrixException
{
public:
  MatrixException(string msg): msg(msg) {};
private:
  string msg;
};

class SizeException: public MatrixException 
{
public:
  SizeException(): MatrixException("Sizes don't match") {};
private:
  string msg;
};
class EmptyException: public MatrixException 
{
public:
  EmptyException(): MatrixException("Matrix empty") {};
private:
  string msg;
};
class FillException: public MatrixException 
{
public:
  FillException(): MatrixException("Matrix fill") {};
private:
  string msg;
};
class RowException: public MatrixException 
{
public:
  RowException(): MatrixException("Row's index error") {};
private:
  string msg;
};
