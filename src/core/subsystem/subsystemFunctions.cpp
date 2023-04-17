/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Extra subsystem functions for auton routine.
 */

#include "main.h"

/* Catapult */
// Reload the catapult
void loadCatapult() {
	pros::Task task{[=] {
        if (cataLoaded == false) {
			// Change LED colour
			bodyLED.set_all(0xffff00);

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
		}
    }};
}

// Fire catapult
void fireCatapult() {
	pros::Task task{[=] {
        if (cataLoaded == true) {
			myLights.pulse(0xffff00, 4, 10);

			// Fire cata
			catapult.move_voltage(12000);

			// Change LED colour
			bodyLED.set_all(0xEE574E);

			// Delay and brake motors
			pros::delay(1000);
			catapult.brake();

			// Set cataLoaded to false
			cataLoaded = false;
		}
    }};
}

// Spin rollers
void rollerAuton() {
	roller.move_voltage(-5000);

	drivetrainMove(6000, 1000);
    roller.brake();

	drivetrainMove(-3000, 1000);
}

// Move discs OUT of the intake
void dispenseDiscs() {
	// Dispense discs
	intake.move_voltage(-12000);
	pros::delay(6000);
	intake.brake();
}