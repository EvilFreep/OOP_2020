#pragma once
#include "CBody.h"

class CCylinder final : public CBody
{
public:
	CCylinder(double density, double baseRadius, double height);
	double GetVolume() const override;
	double GetHeight() const;
	double GetBaseRadius() const;
private:
	virtual void OtherParameters(ostream& output) const override;
	double height;
	double baseRadius;
};