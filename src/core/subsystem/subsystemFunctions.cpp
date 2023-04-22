/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Extra subsystem functions for auton routine.
 */

#include "declaration.hpp"
#include "main.h"

/* Catapult */
// Reload the catapult
void loadCatapult() {
	pros::Task loadCata{[=] {
		// Change LED colour
		bodyLED.set_all(0x27D507);
		bodyLED.update();

		// Load cata until brightness is lower than threshold
		while(cataPosition.get_value() > 2800) {
			catapult.move_voltage(8000);
		}

		// Stop catapult and hold position
		catapult.brake();

		// Set cataLoaded to true
		cataLoaded = true;

		// Vibrate controller
		controller.rumble(". .");

		// Change LED colour
		bodyLED.set_all(0x27D507);
		bodyLED.update();
	}};
}

// Fire catapult
void fireCatapult() {
    if (cataLoaded == true) {
		// Fire cata
		catapult.move_voltage(12000);

		// Change LED colour
		bodyLED.set_all(0xEE574E);
		bodyLED.update();

		// Delay and brake motors
		pros::delay(200);
		catapult.move_voltage(0);

		// Set cataLoaded to false
		cataLoaded = false;
	}
}

// Spin rollers
void rollerAuton() {

}

// Move discs OUT of the intake
void dispenseDiscs() {

}