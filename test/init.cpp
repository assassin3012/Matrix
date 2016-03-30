#include "matrix.h"
#include <catch.hpp>
#include <fstream>

SCENARIO("Matrix init", "[init]") {
	GIVEN("The number of rows and columns") {
		auto rows = 3;
		auto columns = 4;
		WHEN("Create instansce of Matrix") {
			Matrix A(rows, columns);
			Matrix B(rows*2+columns,columns*2+rows);
			Matrix C;
			THEN("The number of rows and columns must be preserved") {
				REQUIRE(A.Rows() == rows);
				REQUIRE(A.Columns() == columns);
				REQUIRE(B.Rows() == 2*rows+columns);
				REQUIRE(B.Columns() == 2*columns+rows);
				REQUIRE(C.Rows() == 0);
				REQUIRE(C.Columns() == 0);
			}
		}
	}
}

SCENARIO("Matrix operator+", "[addition]") {
	Matrix A,B,AB,result;
	A.FillFromFile("A22.txt");
	B.FillFromFile("B.txt");
	result.FillFromFile("A+B.txt");
	AB=A+B;
	REQUIRE(A==AB);
	REQUIRE(B==result);
}
SCENARIO("Matrix operator-", "[subtraction]") {
	Matrix A,B,AB,result;
	A.FillFromFile("A.txt");
	B.FillFromFile("B.txt");
	result.FillFromFile("A-B.txt");
	AB=A-B;
	REQUIRE(result==AB);
}
SCENARIO("Matrix operator*", "[multiplication]") {
	Matrix A,B,AB,result;
	A.FillFromFile("A.txt");
	B.FillFromFile("B.txt");
	result.FillFromFile("AxB.txt");
	AB=A*B;
	REQUIRE(result==AB);
}
