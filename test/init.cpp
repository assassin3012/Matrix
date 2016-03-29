#include "matrix.h"
#include <catch.hpp>
#include <fstream>

SCENARIO("Matrix init", "[init]") {
	GIVEN("The number of rows and columns") {
		auto rows = 3;
		auto columns = 4;
		WHEN("Create instansce of Matrix") {
			Matrix A(rows, columns);
			Matrix B(rows*2+1,columns*2+1);
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
SCENARIO("Matrix Maxelement()", "[Maxelement]") {
	Matrix A;
	A.FillFromFile("A.txt");
	REQUIRE(A.Maxelement() == 6);
}
SCENARIO("Matrix Minelement()", "[Minelement]") {
	Matrix A;
	A.FillFromFile("A.txt");
	REQUIRE(A.Maxelement() == 1);
}
SCENARIO("Matrix operator+", "[+]") {
	Matrix A,B,AB,result;
	A.FillFromFile("A.txt");
	B.FillFromFile("B.txt");
	result.FillFromFile("A+B.txt");
	AB=A+B;
	REQUIRE(result==AB);
}
SCENARIO("Matrix operator-", "[-]") {
	Matrix A,B,AB,result;
	A.FillFromFile("A.txt");
	B.FillFromFile("B.txt");
	result.FillFromFile("A-B.txt");
	AB=A-B;
	REQUIRE(result==AB);
}
SCENARIO("Matrix operator*", "[*]") {
	Matrix A,B,AB,result;
	A.FillFromFile("A.txt");
	B.FillFromFile("B.txt");
	result.FillFromFile("AxB.txt");
	AB=A*B;
	REQUIRE(result==AB);
}
