#include "CBody.h"

CBody::CBody(string type, double density)
{
	CBody::density = density;
	CBody::type = type;
}

double CBody::GetDensity()
{
	return CBody::density;
}

double CBody::GetResultingForceInWater()
{
	return (GetDensity() - FLUID_DENSITY) * GetVolume() * FREE_FALL_ACCELERATION;
}

double CBody::GetMass()
{
	return GetDensity() * GetVolume();
}

void CBody::Print(std::ostream& output)
{
	output << "Type: " << type
		   << "\nDensity: " << GetDensity()
		   << "\nVolume: " << GetVolume()
		   << "\nMass: " << GetMass()
		   << "\nResulting Force in water: " << GetResultingForceInWater()
		   << std::endl;
	OtherParameters(output);
}