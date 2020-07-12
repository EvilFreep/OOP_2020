#include "HtmlDecode.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string htmlLine;

    getline(cin, htmlLine);
    cout << HtmlDecode(htmlLine) << endl;

    return 0;
}