#include <iostream>
#include <fstream>
#include <iomanip>
#include "invert.h"

using namespace std;

float findDet(float matrix[3][3])
{
    float det = matrix[0][0] * matrix[1][1] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1]
        - matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0]
        + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0];
    return det;
}

void invertMat(float matrix[3][3], float invMatrix[3][3], float& det)
{
    invMatrix[0][0] = 1 / det * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
    invMatrix[1][0] = 1 / det * (-1 * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]));
    invMatrix[2][0] = 1 / det * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
    invMatrix[0][1] = 1 / det * (-1 * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]));
    invMatrix[1][1] = 1 / det * (matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2]);
    invMatrix[2][1] = 1 / det * (-1 * (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]));
    invMatrix[0][2] = 1 / det * (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);
    invMatrix[1][2] = 1 / det * (-1 * (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]));
    invMatrix[2][2] = 1 / det * (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
}

int initializationOfMatrix(char** argv, float  matrix[3][3], bool& retflag)
{
    retflag = true;
    ifstream matrixFile(argv[1]);
    ofstream out("output.txt");
    if (!matrixFile.is_open())
    {
        out << "Can't open matrix file" << endl;
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrixFile >> matrix[i][j];
        }
    }
    retflag = false;
    return {};
}

void printMartix(float  invertMatrix[3][3])
{
    ofstream out("output.txt");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            out << fixed << setprecision(3) << invertMatrix[i][j] << " ";
        }
        out << endl;
    }
}

int main(int argc, char* argv[])
{
    const string DETERM_EQUAL_ERR = "Determ of matrix is equal zero\nImpossible inverse matrix";
    float matrix[3][3];
    float invertMatrix[3][3];

    bool retflag;
    int retval = initializationOfMatrix(argv, matrix, retflag);
    if (retflag) return retval;

    float det = findDet(matrix);
    if (det == 0)
    {
        cout << DETERM_EQUAL_ERR << endl;
        return 1;
    }

    invertMat(matrix, invertMatrix, det);

    printMartix(invertMatrix);
}