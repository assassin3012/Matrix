#pragma once

class MatrixException
{
public:
  MatrixException(char* msg): msg(msg) {};
private:
  char* msg;
};

class SizeException: public MatrixException 
{
public:
  SizeException(): MatrixException("Sizes don't match") {};
private:
  char* msg;
};
class EmptyException: public MatrixException 
{
public:
  EmptyException(): MatrixException("Matrix empty") {};
private:
  char* msg;
};
class FillException: public MatrixException 
{
public:
  FillException(): MatrixException("Matrix fill") {};
private:
  char* msg;
};
class RowException: public MatrixException 
{
public:
  RowException(): MatrixException("Row's index error") {};
private:
  char* msg;
};
