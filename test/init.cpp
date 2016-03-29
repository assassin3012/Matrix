#include "matrix.h"
#include <catch.hpp>
#include <fstream>

SCENARIO("Matrix init", "[init]") {
	GIVEN("The number of rows and columns") {
		auto rows = 3;
		auto columns = 3;
		WHEN("Create instansce of Matrix") {
			Matrix A(rows, columns);
			Matrix B(rows*2+1,columns*2+1);
			Matrix C;
			THEN("The number of rows and columns must be preserved") {
				REQUIRE(A.Rows() == rows);
				REQUIRE(A.Columns() == columns);
				REQUIRE(B.Rows() == 2*rows+1);
				REQUIRE(B.Columns() == 2*columns+1);
				REQUIRE(C.Rows() == 0);
				REQUIRE(C.Columns() == 0);
			}
		}
	}
}
