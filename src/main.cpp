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

		/* Subsystems */
		refreshIntake();
		refreshSlapper();
		refreshWings();

		// Crazy? I was crazy once. They put me in elo. Low elo. A low elo with rats in it. And rats make me crazy.
		controller.print(1, 0, "%.0lfC %.0lfC %.0lfC", leftDrive->get_temperature(), slapper.get_temperature(), intake.get_temperature());

		pros::delay(10); // Run for 10 ms then update
	}
}