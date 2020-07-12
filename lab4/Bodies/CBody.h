#pragma once
#include "includes.h"


class CBody
{
public:
	CBody(string type, double density);
	double GetDensity();
	virtual double GetVolume() const = 0;
	double GetResultingForceInWater();
	double GetMass();
	void Print(std::ostream& output);
private:
	virtual void OtherParameters(std::ostream& output) const = 0;
	double density;
	std::string type;
};

const double FREE_FALL_ACCELERATION = 10;
const double FLUID_DENSITY = 1000;