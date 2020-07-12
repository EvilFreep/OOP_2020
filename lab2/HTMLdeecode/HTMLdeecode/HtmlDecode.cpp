#include "HtmlDecode.h"

using namespace std;

string replaceHtmlItem(string html, size_t pos)
{
	size_t htmlItemPos = 0;

	while (htmlItemPos != string::npos)
	{
		htmlItemPos = html.find(htmlEntities[pos], htmlItemPos);
		if (htmlItemPos != string::npos)
		{
			html.replace(htmlItemPos, htmlEntities[pos].length(), htmlEntities[pos + 1]);
		}
	}

	return html;
}

string HtmlDecode(string const& html)
{
	string resultStr = html;
	string item;
	size_t pos = 0;

	while (pos < htmlEntities.size())
	{
		item = htmlEntities[pos];
		resultStr = replaceHtmlItem(resultStr, pos);
		pos += 2;
	}

	return resultStr;
}

