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

void drivetrainMove(int voltage, int time) {
	// Drive forward based on voltage
	frontLeft.move_voltage(voltage);
	backLeft.move_voltage(voltage);
	frontRight.move_voltage(voltage);
	backRight.move_voltage(voltage);

	pros::delay(time);
	drivetrainBrake();
}

void drivetrainBrake() {
	// Stop drivetrain
	frontLeft.brake();
	backLeft.brake();
	frontRight.brake();
	backRight.brake();
}

void drivetrainTurn(int dir, int time) {
	frontLeft.move_voltage(-3000 * dir);
	backLeft.move_voltage(-3000 * dir);
	frontRight.move_voltage(3000 * dir);
	backRight.move_voltage(3000 * dir);

	pros::delay(time);
	drivetrainBrake();
}

void rollerAuton() {
	roller.move_voltage(-6000);

	drivetrainMove(6000, 800);
    roller.brake();

	drivetrainMove(-3000, 200);
}

void dispenseDiscs() {
	// Dispense discs
	intake.move_voltage(-12000);
	pros::delay(6000);
	intake.brake();
}

void autonomous() {
    switch (autonSelection) {
		case RED_1:
			rollerAuton();

			drivetrainTurn(-1, 2200);

			drivetrainMove(4000, 3200);

			dispenseDiscs();
			break;
		case BLUE_1:
			rollerAuton();

			drivetrainTurn(-1, 2200);

			drivetrainMove(4000, 3200);

			dispenseDiscs();
			break;
		case RED_2:
            drivetrainMove(3000, 2100);
			drivetrainTurn(1, 2000);
			drivetrainMove(2000, 2000);

			rollerAuton();

			drivetrainMove(-2000, 500);
			drivetrainTurn(1, 2000);
			drivetrainMove(4000, 3200);

			dispenseDiscs();
			break;
		case BLUE_2:
            drivetrainMove(3000, 2100);
			drivetrainTurn(1, 2000);
			drivetrainMove(2000, 2000);

			rollerAuton();

			drivetrainMove(-2000, 500);
			drivetrainTurn(1, 2000);
			drivetrainMove(4000, 3200);

			dispenseDiscs();
			break;
		case RED_3:
			rollerAuton();
			break;
		case BLUE_3:
			rollerAuton();
			break;
		case RED_4:
			drivetrainMove(6000, 1000);

			intake.move_voltage(-12000);
			pros::delay(6000);
			intake.brake();
			break;
		case BLUE_4:
			drivetrainMove(6000, 1000);

			intake.move_voltage(-12000);
			pros::delay(6000);
			intake.brake();
			break;
			
		case RED_5:
			break;
		case BLUE_5:
			break;
			
		case SKILLS:
			break;
	}
}