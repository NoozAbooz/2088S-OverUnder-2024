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
	Gif gif("/usd/logo2.gif", lv_scr_act());
	while (true) { // Main continuous loop
		/* Drive */
		arcadeDrive();

		/* Subsystem Listeners */
		refreshIntake();
		refreshLift();
		refreshSlapper();
		refreshWings();

		// Report temperature telemetry (this line of code has never worked from the beginning)
		controller.print(0, 0, "D%.0lf S%.0lf %d %.0lf,%.0lf", driveMotor.get_temperature(), slapper.get_temperature(), strait::selector::auton, chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);

		pros::delay(10); // Delay to save resources on brain
	}
}
