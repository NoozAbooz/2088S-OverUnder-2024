#include "main.h"

void arcadeDrive() {
	int power = driveCurve(controller.get_analog(ANALOG_LEFT_Y), 15);
 	int turn = driveCurve(controller.get_analog(ANALOG_RIGHT_X), 4);

	chassis.arcade(power, turn);
}

// Calculates the output of a drive curve function.
// The function takes an input value and a curve value, and applies a curve to the input value.
// The curve value determines the steepness of the curve.
// The function returns the output value after applying the curve.
// Parameters:
// - input: The input value to apply the curve to.
// - curve: The curve value that determines the steepness of the curve.
// Returns: The output value after applying the curve.
double driveCurve(double input, double curve) {
	return (powf(2.718, -(curve / 10)) + powf(2.718, (fabs(input) - 127) / 10) * (1 - powf(2.718, -(curve / 10)))) * input;
}
