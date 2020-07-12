#include "VectorFunctions.h"

vector<double> fillVector(std::istream& input)
{
    return std::vector<double>(std::istream_iterator<double>(input), (std::istream_iterator<double>()));
}

double searchForTheHalfMaxNum(vector<double>& arrayOfFloatNums)
{
    double maxNum = -DBL_MIN;

    for (double i = 0; i < arrayOfFloatNums.size(); i++)
    {
        if (maxNum < arrayOfFloatNums[i])
        {
            maxNum = arrayOfFloatNums[i];
        }
    }

    return maxNum/(double)2;
}

bool proccesingOfVec(vector<double>& arrayOfFloatNums)
{
    double halfMaxNum = 0;

    halfMaxNum = searchForTheHalfMaxNum(arrayOfFloatNums);
    if (halfMaxNum == 0)
    {
        return false;
    }

    for (int i = 0; i < arrayOfFloatNums.size(); i++)
    {
        arrayOfFloatNums[i] /= halfMaxNum;
    }

    return true;
}

void printArray(vector<double>& arrayOfFloatNums, ostream& output)
{
    for (int i = 0; i < arrayOfFloatNums.size(); i++)
    {
        output << fixed << setprecision(3) << arrayOfFloatNums[i] << " ";
    }
    output << endl;
}
