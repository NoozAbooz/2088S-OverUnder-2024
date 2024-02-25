#include "main.h"

namespace strait
{
	double driveCurve(double input, double curve) {
		input = input * (12000.0 / 127.0); // convert motor values to voltages
		return (powf(2.718, -(curve / 10)) + powf(2.718, (fabs(input) - 127) / 10) * (1 - powf(2.718, -(curve / 10)))) * input;
	}
}
