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
		refreshCatapult();
		refreshIntake();
		refreshWings();

		// Crazy? I was crazy once. They put me in elo. Low elo. A low elo with rats in it. And rats make me crazy.
		controller.print(1, 0, "Cat%.0lf°C In%.0lf°C %d", catapult.get_temperature(), intake.get_temperature(), !cataLock);

		pros::delay(10); // Run for 10 ms then update
	}
}