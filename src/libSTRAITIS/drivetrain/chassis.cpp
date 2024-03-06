#include "main.h"

using namespace strait;

void strait::moveRaw(int voltage, int time) {
		leftDrive.move_voltage(voltage);
		rightDrive.move_voltage(voltage);

		pros::delay(time);

		leftDrive.move_voltage(0);
		rightDrive.move_voltage(0);
}
