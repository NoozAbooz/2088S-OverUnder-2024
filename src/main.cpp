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
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	int rotCurve = 10;

	while (true) { // Main continuous loop
		/* Drive */
		//strait::arcadeDrive(12, 1);
		
		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
			int rotCurve = rotCurve + 0.1;
		} else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			int rotCurve = rotCurve - 0.1;
		}
		//printf("Rotational Curve: %d\n", rotCurve);
		strait::arcadeDrive(12, rotCurve);

		/* Subsystem Listeners */
		refreshIntake();
		refreshLift();
		refreshSlapper();
		refreshWings();

		// Report temperature telemetry (this code has never worked since the beginning 😭)
		double drivetrainTemps = strait::vector_average(leftDrive.get_temperatures());
		controller.print(0, 0, "D%.0lf S%.0lf %d %.0lf,%.0lf", drivetrainTemps, slapper.get_temperature(), strait::selector::auton, rotCurve);

		pros::delay(100); // Delay to save resources on brain
	}
}
