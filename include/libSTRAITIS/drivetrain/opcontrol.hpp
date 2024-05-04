#pragma once
#include "main.h"

namespace strait
{
	double driveCurve(double input, double curve);
	void arcadeDrive(int linCurve, int rotCurve, double turnScale);
}