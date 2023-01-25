#include "main.h"
#include "pros/rtos.hpp"

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

void drivetrainMove(int voltage) {
	// Drive forward based on voltage
	frontLeft.move_voltage(voltage);
	backLeft.move_voltage(voltage);
	frontRight.move_voltage(voltage);
	backRight.move_voltage(voltage);
}

void drivetrainBrake() {
	// Stop drivetrain
	frontLeft.brake();
	backLeft.brake();
	frontRight.brake();
	backRight.brake();
}

void drivetrainTurn(int dir) {
	frontLeft.move_voltage(3000 * dir);
	backLeft.move_voltage(3000 * dir);
	frontRight.move_voltage(-3000 * dir);
	backRight.move_voltage(-3000 * dir);
}

void rollerAuton() {
	roller.move_voltage(3000);

	drivetrainMove(6000);
	pros::delay(500);
	drivetrainBrake();
    roller.brake();

	drivetrainMove(-3000);
	pros::delay(500);
	drivetrainBrake();
}

void autonomous() {
    switch (autonSelection) {
		case RED_1:
			rollerAuton();
			break;
		case BLUE_1:
			rollerAuton();
			break;

		case RED_2:
            rollerAuton();
			break;
		case BLUE_2:
            rollerAuton();
			break;
			
		case RED_3:
			drivetrainMove(6000);
			pros::delay(1000);
			drivetrainBrake();

			intake.move_voltage(-12000);
			pros::delay(1000);

			intake.brake();
			break;
		case BLUE_3:
			drivetrainMove(6000);
			pros::delay(1000);
			drivetrainBrake();

			intake.move_voltage(-12000);
			pros::delay(1000);

			intake.brake();
			break;
			
		case RED_4:
			break;
		case BLUE_4:
			break;
			
		case RED_5:
			break;
		case BLUE_5:
			break;
			
		case SKILLS:
			break;
	}
}