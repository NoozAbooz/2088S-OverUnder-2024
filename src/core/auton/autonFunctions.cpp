#include "main.h"
#include "pros/rtos.hpp"

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
	frontLeft.move_voltage(-6000 * dir);
	backLeft.move_voltage(-6000 * dir);
	frontRight.move_voltage(6000 * dir);
	backRight.move_voltage(6000 * dir);

	pros::delay(time);
	drivetrainBrake();
}

void rollerAuton() {
	roller.move_voltage(-5000);

	drivetrainMove(6000, 1000);
    roller.brake();

	drivetrainMove(-3000, 1000);
}

void dispenseDiscs() {
	// Dispense discs
	intake.move_voltage(-12000);
	pros::delay(6000);
	intake.brake();
}
