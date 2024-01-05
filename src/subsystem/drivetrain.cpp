#include "main.h"

void arcadeDrive() {
	int power = driveCurve(controller.get_analog(ANALOG_LEFT_Y), 15);
 	int turn = driveCurve(controller.get_analog(ANALOG_RIGHT_X), 4);

	chassis.arcade(power, turn);
}

double driveCurve(double input, double curve) {
	return (powf(2.718, -(curve / 10)) + powf(2.718, (fabs(input) - 127) / 10) * (1 - powf(2.718, -(curve / 10)))) * input;
}
