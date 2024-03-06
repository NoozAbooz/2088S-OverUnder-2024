#include "main.h"

void arcadeDrive() {
	// poll joystick input and convert to mv, then run through drivecurve function
	int power = strait::driveCurve(strait::toMilivolt(controller.get_analog(ANALOG_LEFT_Y)), 12);
 	int turn = strait::driveCurve(strait::toMilivolt(controller.get_analog(ANALOG_RIGHT_X)), 1);

	// move motors based on direction (eg move left more when turn is positive)
	leftDrive.move_voltage((power + turn));
	rightDrive.move_voltage((power - turn));
}