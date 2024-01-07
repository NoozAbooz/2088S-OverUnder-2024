#include "main.h"

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

		/* Subsystem Listeners */
		refreshIntake();
		refreshSlapper();
		refreshWings();

		// Report temperature telemetry (this line of code has never worked from the beginning)
		controller.print(1, 0, "%.0lfC S%.0lfC I%.0lfC", leftDrive->get_temperature(), slapper.get_temperature(), intake.get_temperature());

		pros::delay(10); // Delay to save resources on brain
	}
}