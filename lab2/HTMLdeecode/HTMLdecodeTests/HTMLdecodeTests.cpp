#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../HTMLdeecode/HtmlDecode.h"

TEST_CASE("replaceHtmlItem_strLine_noChangedLine")
{
	string line = "Sasah kushal kashu";
	string res = replaceHtmlItem(line, 0);

	REQUIRE(res == line);
}

TEST_CASE("replaceHtmlItem_HtmlEntityLine_changedLine")
{
	string line = "&quot;";
	string expected = "\"";
	string res = replaceHtmlItem(line, 0);

	REQUIRE(res == expected);
}

TEST_CASE("HtmlDecode_lineWithoutHtmlEntities_noChangedLine")
{
	string line = "Sasah kushal kashu";
	string res = HtmlDecode(line);

	REQUIRE(res == line);
}

TEST_CASE("HtmlDecode_lineWithHtmlEntities_ChangedLine")
{
	string line = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	string res = HtmlDecode(line);
	string expected = "Cat <says> \"Meow\". M&M's";

	REQUIRE(res == expected);
}