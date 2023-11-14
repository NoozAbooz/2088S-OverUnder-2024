#include "main.h"
#include "globals.hpp"

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
/**
 * The operator control function that runs the robot during teleoperated mode.
 * It continuously drives the robot using arcade drive and refreshes the subsystems.
 * It also prints the temperature of the left drive motor group, catapult, and intake on the controller's screen.
 */
void opcontrol() {
	while (true) {
		/* Drive */
		arcadeDrive();

		/* Subsystems */
		refreshCatapult();
		refreshIntake();
		refreshWings();

		// Crazy? I was crazy once. They put me in elo. Low elo. A low elo with rats in it. And rats make me crazy.
		controller.print(1, 0, "%.0lf°C %.0lf°C %.0lf°C", leftDrive.get_temperature(), catapult.get_temperature(), intake.get_temperature());

		pros::delay(10); // Run for 20 ms then update
	}
}