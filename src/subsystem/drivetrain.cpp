#include "main.h"
#include "globals.hpp"

double joystickCurve = 10;

void arcadeDrive() {
	int power = driveCurve(controller.get_analog(ANALOG_LEFT_Y), joystickCurve);
 	int turn = controller.get_analog(ANALOG_RIGHT_X);
  	leftDrive.move_voltage((power + turn) * (12000 / 127));
  	rightDrive.move_voltage((power - turn) * (12000 / 127));
}

double driveCurve(double input, double curve) {
  return (powf(2.718, -(curve / 10)) + powf(2.718, (fabs(input) - 127) / 10) * (1 - powf(2.718, -(curve / 10)))) * input;
}

