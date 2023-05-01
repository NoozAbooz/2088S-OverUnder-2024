/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Extra subsystem functions for auton routine.
 */

#include "declaration.hpp"
#include "main.h"
#include "pros/rtos.hpp"

/* Catapult */
// Reload the catapult
void loadCatapult() {
	// Change LED colour
	bodyLED.set_all(0xFFD972);
	bodyLED.update();

	for(int i = 0; i < 20; i++){
		int power = controller.get_analog(ANALOG_LEFT_Y);
    	int turn = controller.get_analog(ANALOG_RIGHT_X);
    	int left = (power + turn) * (12000 / 127);
    	int right = (power - turn) * (12000 / 127);
    	leftSide.move_voltage(left);
    	rightSide.move_voltage(right);


		pros::delay(10);
	}
	

	// Load cata until brightness is lower than threshold
	while(cataPosition.get_value() > 2700) {
    	catapult.move_voltage(10000);

		int power = controller.get_analog(ANALOG_LEFT_Y);
    	int turn = controller.get_analog(ANALOG_RIGHT_X);
    	int left = (power + turn) * (12000 / 127);
    	int right = (power - turn) * (12000 / 127);
    	leftSide.move_voltage(left);
    	rightSide.move_voltage(right);

		pros::delay(10);
	}

	// Stop catapult and hold position
	catapult.brake();

	// Set cataLoaded to true
	cataLoaded = true;

	// Change LED colour
	bodyLED.set_all(0x27D507);
	bodyLED.update();

	// Vibrate controller
	controller.rumble(".");
}

// Fire catapult
void fireCatapult() {
    if (cataLoaded == true) {
		// Fire cata
		catapult.move_voltage(12000);

		// Change LED colour
		bodyLED.set_all(0x86E0E7);
		bodyLED.update();

		// Delay and brake motors
		pros::delay(800);
		catapult.move_voltage(0);

		// Set cataLoaded to false
		cataLoaded = false;
	}
}

// Spin rollers
void rollerAuton() {
	intake.move_voltage(-5500);

	drivetrainMove(6000, 2000);
	intake.brake();

	drivetrainMove(-1000, 1000);

}

// Move discs OUT of the intake
void dispenseDiscs() {

}

/* Drivetrain */
void drivetrainMove(int voltage, int time) {
	leftSide.move_voltage(voltage);
	rightSide.move_voltage(voltage);

	pros::delay(time);

	leftSide.brake();
	rightSide.brake();
}