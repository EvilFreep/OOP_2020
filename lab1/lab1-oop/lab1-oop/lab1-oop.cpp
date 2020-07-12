#include <iostream>
#include <fstream>
#include <string>
#include <optional>

using namespace std;

struct Args
{
    string fin;
    string fout;
    string searchStr;
    string replaceStr;
};

//парсим аргументы и проверяем их кол-во
optional<Args> parseArgs(int argc, char* argv[])
{
    if (argc != 5)
    {
        return nullopt;
    }
    Args args;
    args.fin = argv[1];
    args.fout = argv[2];
    args.searchStr = argv[3];
    args.replaceStr = argv[4];
    return args;
}

void replaceInToOut(int& pos, string& line, optional<Args>& args, ofstream& output)
{
    while (pos != string::npos)
    {
        line.erase(pos, args->searchStr.length());
        line.insert(pos, args->replaceStr);
        pos = line.find(args->searchStr, pos + args->replaceStr.length());
    }
    output << line << endl;
}

void copyInToOut(ifstream& input, optional<Args>& args, ofstream& output)
{
    string line;
    int pos;
    while (getline(input, line))
    {
        pos = line.find(args->searchStr);
        if (pos != string::npos)
        {
            replaceInToOut(pos, line, args, output);
        }
        else output << line << endl;
    }
}

bool checkOpenFile(ifstream& input, optional<Args>& args)
{
    const string fileErr = "file ",
        cantBeOpenedErr = " can't be opened";
    if (!input.is_open())
    {
        cout << fileErr << args->fin << cantBeOpenedErr << endl;
        return false;
    }
    return true;
}

bool checkOpenFile(ofstream& input, optional<Args>& args)
{
    const string fileErr = "file ",
        cantBeOpenedErr = " can't be opened";
    if (!input.is_open())
    {
        cout << fileErr << args->fout << cantBeOpenedErr << endl;
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    const string incorrectNumOfArgsErr = "incorrect numer of argumetns.",
        rightVersionErr = "right version: <input file> <output file> <search string> <replace string>",
        failedReadDataErr = "Failed to read data from input file",
        writingDataErr = "Error writing output file";
    auto args = parseArgs(argc, argv);

    if (!args)
    {
        cout << incorrectNumOfArgsErr << endl;
        cout << rightVersionErr << endl;
        return 1;
    }

    ifstream input(args->fin);
    ofstream output(args->fout);

    //проверяем открытие input
    if (!checkOpenFile(input, args))
    {
        return 1;
    }

    //проверяем открытие output
    if (!checkOpenFile(output, args))
    {
        return 1;
    }

    //кпоируем с инпута в оутпут, заменяя искомые строки, если они есть
    copyInToOut(input, args, output);

    //проверка на bad
    if (input.bad())
    {
        cout << failedReadDataErr << endl;
        return 1;
    }

    //проверка на flush
    if (!output.flush())
    {
        cout << writingDataErr << endl;
        return 1;
    }

    return 0;
}