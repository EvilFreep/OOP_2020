#include "CCone.h"

CCone::CCone(double density, double baseRadius, double height)
	:CBody("Cone", density),
	baseRadius(baseRadius),
	height(height)
{}

double CCone::GetBaseRadius() const
{
	return CCone::baseRadius;
}

double CCone::GetHeight() const
{
	return CCone::height;
}

double CCone::GetVolume() const
{
	return (M_PI * baseRadius * baseRadius * height) / 3;
}

void CCone::OtherParameters(ostream& output) const
{
	output << "Height: " << GetHeight()
		<< "\nBase radius: "<< GetBaseRadius() << endl;
}