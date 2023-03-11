/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Extra subsystem functions for auton routine.
 * @date 2023-03-10
 */

#include "main.h"

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

void reloadCatapult() {
	roller.move_voltage(-5000);

	drivetrainMove(6000, 1000);
    roller.brake();

	drivetrainMove(-3000, 1000);
}