#include "CCylinder.h"

CCylinder::CCylinder(double density, double baseRadius, double height):CBody("Cylinder", density),
	baseRadius(baseRadius),
	height(height)
{}

double CCylinder::GetBaseRadius() const
{
	return CCylinder::baseRadius;
}

double CCylinder::GetHeight() const
{
	return CCylinder::height;
}

double CCylinder::GetVolume() const
{
	return M_PI * baseRadius * baseRadius * height;
}

void CCylinder::OtherParameters(ostream& output) const
{
	output << "Height: " << GetHeight()
		   << "\nBase radius: " << GetBaseRadius()<< endl;
}