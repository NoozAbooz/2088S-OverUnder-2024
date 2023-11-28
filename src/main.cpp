#include "globals.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled.
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will not resume 
 * the task from where it left off.
 */

void opcontrol() {
	while (true) { // Main continuous loop
		/* Drive */
		arcadeDrive();

		/* Subsystems */
		refreshCatapult();
		refreshIntake();
		//refreshWings();

		// Crazy? I was crazy once. They put me in elo. Low elo. A low elo with rats in it. And rats make me crazy.
		controller.print(1, 0, "%.0lf°C %.0lf°C %.0lf°C", leftDrive.get_temperature(), catapult.get_temperature(), intake.get_temperature());

		pros::delay(20); // Run for 20 ms then update
	}
}