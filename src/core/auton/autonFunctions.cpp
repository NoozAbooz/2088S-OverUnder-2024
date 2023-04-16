/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Extra subsystem functions for auton routine.
 * @date 2023-03-10
 */

#include "main.h"

// Auto-reload the catapult
void loadCatapult() {
	if (cataLoaded == false) {
		while(cataPosition.get_value() > 2800) {
    		catapult.move_voltage(8000);
		}

		catapult.brake();

		// Set cataLoaded to true
		cataLoaded = true;
	}
	
}

// Spin rollers
void rollerAuton() {
	//roller.move_voltage(-5000);

	//drivetrainMove(6000, 1000);
    //roller.brake();

	//drivetrainMove(-3000, 1000);
}

// Move discs OUT of the intake
void dispenseDiscs() {
	// Dispense discs
	intake.move_voltage(-12000);
	pros::delay(6000);
	intake.brake();
}