#include "main.h"

void arcadeDrive() {
	int power = strait::driveCurve(controller.get_analog(ANALOG_LEFT_Y), 12);
 	int turn = strait::driveCurve(controller.get_analog(ANALOG_RIGHT_X), 0.5);

	// move motors and convert from joystick to voltage for accuracy
	leftDrive.move_voltage((power + turn) * (12000 / 127));
	rightDrive.move_voltage((power - turn) * (12000 / 127));
}