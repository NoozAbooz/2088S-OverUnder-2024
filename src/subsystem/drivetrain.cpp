#include "main.h"

void arcadeDrive() {
	int power = driveCurve(controller.get_analog(ANALOG_LEFT_Y), 12);
 	int turn = driveCurve(controller.get_analog(ANALOG_RIGHT_X), 3);

	leftDrive->move_voltage((power + turn) * (12000 / 127));
	rightDrive->move_voltage((power - turn) * (12000 / 127));
}

double driveCurve(double input, double curve) {
	return (powf(2.718, -(curve / 10)) + powf(2.718, (fabs(input) - 127) / 10) * (1 - powf(2.718, -(curve / 10)))) * input;
}
