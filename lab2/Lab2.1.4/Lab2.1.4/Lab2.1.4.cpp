//поделить каждый элемент массива на половину максимального элемента
#include <iostream>
#include "VectorFunctions.h"

using namespace std;

int main()
{
    vector<double> arrayOfNums;

    try
    {
        arrayOfNums = fillVector(cin);
        if (arrayOfNums.empty())
        {
            throw EMPTY_VECTOR_ERROR;
        }
    }
    catch (const string & EMPTY_VECTOR_ERROR)
    {
        cout << EMPTY_VECTOR_ERROR << endl;
        return 1;
    }

    try
    {
        if (!proccesingOfVec(arrayOfNums))
        {
            throw MAX_NUM_IS_ZERO_ERROR;
        }

        printArray(arrayOfNums, cout);
    }
    catch (const string & MAX_NUM_IS_ZERO_ERROR)
    {
        cout << MAX_NUM_IS_ZERO_ERROR << endl;
        return 1;
    }
    
    return 0;
}