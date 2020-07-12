#pragma once
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
const vector<string> htmlEntities =
{
		"&quot;", "\"" , "&apos;", "'", "&lt;", "<", "&gt;", ">", "&amp;", "&"
};

string HtmlDecode(string const& html);
string replaceHtmlItem(string html, size_t pos);