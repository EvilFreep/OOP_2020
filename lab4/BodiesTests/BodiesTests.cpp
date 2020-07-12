#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../Bodies/CBody.h"
#include "../Bodies/CCone.h"
#include "../Bodies/CCylinder.h"
#include "../Bodies/CParallelepiped.h"
#include "../Bodies/CSphere.h"
#include "../Bodies/Interface.h"

TEST_CASE("Cone test")
{
	CCone cone = CCone(1206, 1.003, 23.43);

	SECTION("GetDencity_returned")
	{
		REQUIRE(cone.GetDensity() == 1206);
	}
	SECTION("GetBaseRadius_returned")
	{
		REQUIRE(cone.GetBaseRadius() == 1.003);
	}
	SECTION("GetHeigth_returned")
	{
		REQUIRE(cone.GetHeight() == 23.43);
	}
	SECTION("GetMass_returned")
	{
		REQUIRE(cone.GetMass() == 29767.698);
	}
	SECTION("GetVoulme_returned")
	{
		REQUIRE(cone.GetVolume() == 24.683);
	}
	SECTION("GetResultingForceInWater_returned")
	{
		REQUIRE(cone.GetResultingForceInWater() == 50846.98);
	}
}

TEST_CASE("Cylinder_tests")
{
	CCylinder cy = CCylinder(700, 12, 2.76);
	SECTION("GetDencity_returned")
	{
		REQUIRE(cy.GetDensity() == 700);
	}
	SECTION("GetBaseRadius_returned")
	{
		REQUIRE(cy.GetBaseRadius() == 12);
	}
	SECTION("GetHeigth_returned")
	{
		REQUIRE(cy.GetHeight() == 2.76);
	}
	SECTION("GetMass_returned")
	{
		REQUIRE(cy.GetMass() == 874016.5);
	}
	SECTION("GetVoulme_returned")
	{
		REQUIRE(cy.GetVolume() == 1248.595);
	}
	SECTION("GetResultingForceInWater_returned")
	{
		REQUIRE(cy.GetResultingForceInWater() == -3745785);
	}
}

TEST_CASE("Parallelepiped_tests")
{
	CParallelepiped p = CParallelepiped(1001, 2, 0.65, 0.21);
	SECTION("GetDencity_returned")
	{
		REQUIRE(p.GetDensity() == 1001);
	}
	SECTION("GetDepth_returned")
	{
		REQUIRE(p.GetDepth() == 0.21);
	}
	SECTION("GetWidth_returned")
	{
		REQUIRE(p.GetWidth() == 2);
	}
	SECTION("GetHeight_returned")
	{
		REQUIRE(p.GetHeight() == 0.65);
	}
	SECTION("GetMass_returned")
	{
		REQUIRE(p.GetMass() == 273.273);
	}
	SECTION("GetResultingForceInWater_returned")
	{
		REQUIRE(p.GetResultingForceInWater() == 2.73);
	}
}

TEST_CASE("Sphere_tests")
{
	CSphere s = CSphere(1002, 3);
	SECTION("GetDencity_returned")
	{
		REQUIRE(s.GetDensity() == 1002);
	}
	SECTION("GetRadius_returned")
	{
		REQUIRE(s.GetRadius() == 3);
	}
	SECTION("GetVolume_returned")
	{
		REQUIRE(s.GetVolume() == 113.097);
	}
	SECTION("GetMass_returned")
	{
		REQUIRE(s.GetMass() == 113323.194);
	}
	SECTION("GetResultingForceInWater_returned")
	{
		REQUIRE(s.GetResultingForceInWater() == 2261.94);
	}
}

TEST_CASE("Interface_tests")
{
	vector<shared_ptr<CBody>> bodies;
	SECTION("FindMaxMass_oneBody_massReturned")
	{
		bodies.push_back(make_shared<CCone>(322, 2.00002, 0.33));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(maxMass->GetMass() == 445.004);
	}
	SECTION("FindMaxMass_twoBodys_sameTypesReturned")
	{
		bodies.push_back(make_shared<CCone>(2010, 2.00002, 0.33));
		bodies.push_back(make_shared<CCone>(130, 2, 2));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(maxMass->GetMass() == 2777.82);
	}
	SECTION("FindMaxMass_bodiesOfDiffTypes_maxMassReturned")
	{
		bodies.push_back(make_shared<CCone>(23000, 2.00002, 0.33));
		bodies.push_back(make_shared<CCylinder>(200, 1.1, 0.2));
		bodies.push_back(make_shared<CParallelepiped>(3110, 3, 3, 4));
		bodies.push_back(make_shared<CSphere>(400, 2));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(maxMass->GetMass() == 111960);
	}
	SECTION("FindMaxMass_identicalBodies_maxMassReturned")
	{
		bodies.push_back(make_shared<CCylinder>(200, 1.1, 0.2));
		bodies.push_back(make_shared<CCylinder>(200, 1.1, 0.2));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(maxMass->GetMass() == 152);
	}

	SECTION("FindMinResultingForceInWater_oneBody_massReturned")
	{
		bodies.push_back(make_shared<CCone>(322, 2.00002, 0.33));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(maxMass->GetResultingForceInWater() == -9369.96);
	}
	SECTION("FindMinResultingForceInWater_twoBodys_sameTypesReturned")
	{
		bodies.push_back(make_shared<CCone>(2010, 2.00002, 0.33));
		bodies.push_back(make_shared<CCone>(130, 2, 2));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(maxMass->GetResultingForceInWater() == 13958.2);
	}
	SECTION("FindMinResultingForceInWater_bodiesOfDiffTypes_maxMassReturned")
	{
		bodies.push_back(make_shared<CCone>(23000, 2.00002, 0.33));
		bodies.push_back(make_shared<CCylinder>(200, 1.1, 0.2));
		bodies.push_back(make_shared<CParallelepiped>(3110, 3, 3, 4));
		bodies.push_back(make_shared<CSphere>(400, 2));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(maxMass->GetResultingForceInWater() == 759600);
	}
	SECTION("FindMinResultingForceInWater_identicalBodies_maxMassReturned")
	{
		bodies.push_back(make_shared<CCylinder>(200, 1.1, 0.2));
		bodies.push_back(make_shared<CCylinder>(200, 1.1, 0.2));
		shared_ptr<CBody> maxMass = FindMaxMass(bodies);
		REQUIRE(maxMass->GetResultingForceInWater() == -6080);
	}
}