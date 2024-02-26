#include "main.h"

namespace strait
{
	double driveCurve(double input, double curve) {
		return (powf(2.718, -(curve / 10)) + powf(2.718, (fabs(input) - 127) / 10) * (1 - powf(2.718, -(curve / 10)))) * input;
	}
}
