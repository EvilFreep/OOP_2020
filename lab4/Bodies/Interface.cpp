#include "Interface.h"

bool CheckCorrectType(int& type)
{
	return type <= SPHERE_TYPE && type >= CALCULATE_TYPE;
}

shared_ptr<CBody> FindMaxMass(const vector<shared_ptr<CBody>>& bodies)
{
	auto maxMass = *max_element(bodies.begin(), bodies.end(),
		[](shared_ptr<CBody> const& first, shared_ptr<CBody> const& second)
		{
			return second->GetMass() > first->GetMass();
		});
	return maxMass;
}

shared_ptr<CBody> FindMinResultingForceInWater(const vector<shared_ptr<CBody>>& bodies)
{
	auto minResultingForceInWater = *min_element(bodies.begin(), bodies.end(),
		[](shared_ptr<CBody> const& first, shared_ptr<CBody> const& second)
		{
			return second->GetResultingForceInWater() > first->GetResultingForceInWater();
		});
	return minResultingForceInWater;
}

void FillBodiesVector(vector<shared_ptr<CBody>>& bodies, istream& input, ostream& output)
{
	int type = -1;
	while (type != CALCULATE_TYPE)
	{
		output << BODY_TYPE_MES;
		input >> type;
		if (!CheckCorrectType) {
			output << UNKNOWN_TYPE_ERR;
		}
		else
		{
			if (type == CALCULATE_TYPE) {
				output << endl;
				break;
			}
			output << DENSITY_MES;
			double density;
			input >> density;
			if (type == CONE_TYPE)
			{
				output << CONE_BASERADIUS_MES;
				double baseRadius;
				input >> baseRadius;
				output << CONE_HEIGHT_MES;
				double height;
				input >> height;
				bodies.push_back(make_shared<CCone>(density, baseRadius, height));
			}
			else if (type == SPHERE_TYPE)
			{
				output << SPHERE_RADIUS_MES;
				double radius;
				input >> radius;
				bodies.push_back(make_shared<CSphere>(density, radius));
			}
			else if (type == PARALLELEPIPED_TYPE)
			{
				output << PARALLELEPIPED_WIDTH_MES;
				double width;
				input >> width;
				output << PARALLELEPIPED_HEIGHT_MES;
				double height;
				input >> height;
				output << PARALLELEPIPED_DEPTH_MES;
				double depth;
				input >> depth;
				bodies.push_back(make_shared<CParallelepiped>(density, width, height, depth));
			}
			else if (type == CYLINDER_TYPE)
			{
				output << CYLINDER_BASERADIUS_MES;
				double baseRadius;
				input >> baseRadius;
				output << CYLINDER_HEIGHT_MES;
				double height;
				input >> height;
				bodies.push_back(make_shared<CCylinder>(density, baseRadius, height));
			}
		}
	}
}

void BodyController(vector<shared_ptr<CBody>> bodies, istream& input, ostream& output)
{
	FillBodiesVector(bodies, input, output);
	for (size_t i = 0; i < bodies.size(); i++)
	{
		PrintInf(bodies[i], output);
	}
	if (bodies.size() != 0) {
		output << BIGGEST_WEIGHT << endl;
		PrintInf(FindMaxMass(bodies), output);
		output << LIGHTEST_BODY_IN_WATER << endl;
		PrintInf(FindMinResultingForceInWater(bodies), output);
	}
}

void PrintInf(const shared_ptr<CBody>& bodies, ostream& output)
{
	CBody* body = bodies.get();
	body->Print(output);
	output << endl;
}