#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    roller.move_voltage(8000);

    pros::delay(400);

    frontLeft.move_voltage(3000);
	backLeft.move_voltage(3000);
    frontRight.move_voltage(3000);
	backRight.move_voltage(3000);

    pros::delay(1000);

    roller.brake();

    pros::delay(1000);

    frontLeft.brake();
	backLeft.brake();
    frontRight.brake();
	backRight.brake();

    frontLeft.move_voltage(-6000);
	backLeft.move_voltage(-6000);
    frontRight.move_voltage(-6000);
	backRight.move_voltage(-6000);

    pros::delay(400);

    frontLeft.brake();
	backLeft.brake();
    frontRight.brake();
	backRight.brake();

    roller.brake();
}