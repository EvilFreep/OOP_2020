#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Lab2.1.4/VectorFunctions.h"

using namespace std;

TEST_CASE("fillVector_strOfNums_vectorOfNumsReturned")
{
	istringstream input ("1 2 3 4 5 6 7 8 9");
	vector<double> dblArray = fillVector(input),
				   result = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	REQUIRE(dblArray == result);
	dblArray.clear();
	result.clear();
}

TEST_CASE("fillvector_emptyLine_errorReturned")
{
	istringstream input("");
	vector<double> dblArray = fillVector(input),
			       result = {};
	REQUIRE(dblArray == result);
	dblArray.clear();
	result.clear();
}

TEST_CASE("proccesingOfVec_VecOfNums_everyElOfVecdivideByHalfOfMaxNum")
{
	vector<double> arr = { 1, 2, 3.32, 4, 5, 6 },
				   result = { (1.0 / 3), (2.0 / 3), (3.32 / 3),(4.0 / 3),(5.0 / 3),(6.0 / 3) };
	proccesingOfVec(arr);
	REQUIRE(arr == result);

	arr.clear();
	result.clear();
}

TEST_CASE("proccesingOfVec_maxNumZero_falseReturned")
{
	vector<double> arr = { -1, -2.22, -3, 0 };

	REQUIRE(proccesingOfVec(arr) == false);
}

TEST_CASE("printArray_VecOfNums_printVector")
{
	ostringstream output;
	vector<double> arr = { 3.66, 6.21, 10 };
	printArray(arr, output);

	REQUIRE(output.str() == "3.660 6.210 10.000 \n");
	arr.clear();
}