#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../TV/TVSet.h"

TEST_CASE("when TV first time turn on channel will be 1")
{
	CTVSet tv;
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 1);
}

TEST_CASE("when TV turned off channel must be 0")
{
	CTVSet tv;
	tv.TurnOff();

	REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("SelectChannel must change channel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(10);
	
	REQUIRE(tv.GetChannel() == 10);
}

TEST_CASE("When tv is turned off u cant select channel")
{
	CTVSet tv;
	tv.SelectChannel(10);

	REQUIRE(tv.GetChannel() == 0);
}

TEST_CASE("After reload channel not changed")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(14);
	tv.TurnOff();
	tv.TurnOn();

	REQUIRE(tv.GetChannel() == 14);
}

TEST_CASE("Check borderline values")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(1);

	REQUIRE(tv.GetChannel() == 1);

	tv.SelectChannel(99);
	REQUIRE(tv.GetChannel() == 99);
}