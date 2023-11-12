#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {


	while (true) {
		/* Drive */
		double joystickCurve = 14;
		int power = driveCurve(controller.get_analog(ANALOG_LEFT_Y), joystickCurve);
    	int turn = driveCurve(controller.get_analog(ANALOG_RIGHT_X), joystickCurve);
    	leftSide.move_voltage((power + turn) * (12000 / 127));
    	rightSide.move_voltage((power - turn) * (12000 / 127));

		printf("Power: %i, Turn: %i\n", power, turn);

		/* Subsystems */
		spinIntake();
		refreshCatapult();

		// Print debug info to controller
    	controller.print(1, 0, "%.0i°C %.0i°C %.0i°C      ", static_cast<int>(leftSide.get_temperature()), static_cast<int>(catapult.get_temperature()), static_cast<int>(intake.get_temperature()));

		// Delay to prevent overloading brain :)
		pros::delay(10);
	}
}