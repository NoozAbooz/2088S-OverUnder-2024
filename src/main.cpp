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
		strait::arcadeDrive(12, 0, 0.5);

		/* Subsystem Listeners */
		refreshIntake();
		refreshLift();
		refreshSlapper();
		refreshWings();

		// Report temperature telemetry (this code has never worked since the beginning 😭)
		double drivetrainTemps = strait::vector_average(leftDrive.get_temperatures());
		controller.print(0, 0, "DT%.0lf %d %.0lf %.0lf", drivetrainTemps, strait::selector::auton, chassis.getPose().x, chassis.getPose().y);

		pros::delay(100); // Delay to save resources on brain
	}
}
