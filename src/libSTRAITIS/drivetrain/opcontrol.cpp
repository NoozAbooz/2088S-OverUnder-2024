#include "main.h"

double strait::driveCurve(double input, double curve) {
	return (powf(2.718, -(curve / 10)) + powf(2.718, (fabs(input) - 127) / 10) * (1 - powf(2.718, -(curve / 10)))) * input;
}

void strait::arcadeDrive(int linCurve, int rotCurve, double turnScale) {
	// poll joystick input and convert to mv, then run through drivecurve function
	int power = strait::driveCurve(controller.get_analog(ANALOG_LEFT_Y), linCurve);
 	int turn = strait::driveCurve((controller.get_analog(ANALOG_RIGHT_X) * turnScale), rotCurve);

	// move motors based on direction (eg move left more when turn is positive)
	leftDrive.move_voltage((power + turn) * (12000.0 / 127));
	rightDrive.move_voltage((power - turn) * (12000.0 / 127));
}