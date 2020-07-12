#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	:CBody("Parallelepiped", density),
	width(width),
	height(height),
	depth(depth)
{}

double CParallelepiped::GetWidth() const
{
	return CParallelepiped::width;
}

double CParallelepiped::GetHeight() const
{
	return CParallelepiped::height;
}

double CParallelepiped::GetDepth() const
{
	return CParallelepiped::depth;
}

double CParallelepiped::GetVolume() const
{
	return depth * height * width;
}

void CParallelepiped::OtherParameters(ostream& output) const
{
	output << "Width: " << GetWidth()
		   << "\nHeight: " << GetHeight()
		   << "\nDepth: " << GetDepth() << endl;
}