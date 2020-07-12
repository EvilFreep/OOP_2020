#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;
const string EMPTY_VECTOR_ERROR = "Vector is empty.";
const string MAX_NUM_IS_ZERO_ERROR = "Maximum number is equal 0";

vector<double> fillVector(std::istream& input);
bool proccesingOfVec(vector<double>& arrayOfFloatNums);
void printArray(vector<double>& arrayOfFloatNums, ostream& output);
