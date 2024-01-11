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
		refreshLift();
		refreshSlapper();
		refreshWings();

		// Report temperature telemetry (this line of code has never worked from the beginning)
		controller.print(1, 0, "Drivetrain %.0lf°C", driveMotor.get_temperature());
		controller.print(2, 0, "Slapper %.0lf°C", slapper.get_temperature());
		controller.print(3, 0, "Intake %.0lf°C", intake.get_temperature());


		pros::delay(10); // Delay to save resources on brain
	}
}