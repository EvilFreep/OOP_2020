#include <iostream>
#include <string>
#include <set>

using namespace std;

int reverseByte(int &number)
{
    number = (number & 0x55) << 1 | (number & 0xAA) >> 1;
    number = (number & 0x33) << 2 | (number & 0xCC) >> 2;
    number = (number & 0x0F) << 4 | (number & 0xF0) >> 4;

    return number;
}

bool checkInputStr(char *argv)
{
    const set<char> ALLOWED_NUMS = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-'};
    string inputNum = argv;
    const string INPUT_INCORRECT_SYM_ERROR = "Your input: ",
                 INPUT_NUMBER_ERROR = "\nInput number please";
    char letter;
    for (int i = 0; i < inputNum.length(); i++)
    {
        letter = inputNum[i];
        if ((i != 0 && letter == '-') || (ALLOWED_NUMS.count(letter) == 0))
        {
            cout << INPUT_INCORRECT_SYM_ERROR << inputNum << INPUT_NUMBER_ERROR << endl;
            return true;
        }
    }

    return false;
}

int main(int argc, char* argv[])
{
    const string INCORRECT_NUMBER_OF_ARG_ERROR = "Incorrect numer of arguments",
                 CORRECT_FORM_OF_INPUT_ERROR = "Correct form: FipByte.exe <number>",
                 INCORRECT_RANGE_OF_NUMBER_ERROR = "Incorrect range of number \nYour number must be greater than -1 and less than 256 \n";
    int num = 0;
    const int MAX_NUM = 255;
    const int MIN_NUM = 0;

    //check incorrect num of args
    if (argc != 2)
    {
        cout << INCORRECT_NUMBER_OF_ARG_ERROR << endl;
        cout << CORRECT_FORM_OF_INPUT_ERROR << endl;
        return 1;
    }

    //check not numeral symbols
    if (checkInputStr(argv[1]))
    {
        return 1;
    }
    
    num = atoi(argv[1]);

    //check range of number
    if (num > MAX_NUM || num < MIN_NUM)
    {
        cout << INCORRECT_RANGE_OF_NUMBER_ERROR;
        return 1;
    }

    cout << reverseByte(num) << endl;
}