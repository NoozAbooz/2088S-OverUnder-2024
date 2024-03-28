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
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
	lightStrip.set_all(0xeb4034);

	while (true) { // Main continuous loop
		/* Drive */
		strait::arcadeDrive(12, 1);

		/* Subsystem Listeners */
		refreshIntake();
		refreshLift();
		refreshSlapper();
		refreshWings();

		// Report temperature telemetry (this line of code has never worked from the beginning)
		double drivetrainTemps = strait::vector_average(leftDrive.get_temperatures());
		controller.print(0, 0, "D%.0lf S%.0lf %d %.0lf,%.0lf", drivetrainTemps, slapper.get_temperature(), strait::selector::auton, chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);

		pros::delay(10); // Delay to save resources on brain
	}
}
