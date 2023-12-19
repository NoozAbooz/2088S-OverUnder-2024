#include "globals.hpp"

// Catapult
bool cataLoaded = false;
bool cataLock = false;

/**
 * @brief Refreshes the catapult subsystem by checking for button presses and locking/unlocking the catapult.
 * 
 */
void refreshCatapult() {
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
		fireCatapult();
		if(cataLock == false) {
			pros::Task loadCataTask(loadCatapult);
		}
	  
	} else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) && cataLock == false) {
	  	pros::Task loadCataTask(loadCatapult);
	}

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
		cataLock = !cataLock;
		controller.rumble("-.-");
		console.println("Cata Locked");
	}
}

/**
 * Loads the catapult until the brightness of the line sensor is lower than the threshold.
 * Sets cataLoaded to true and vibrates the controller when finished.
 */
void loadCatapult() {
	pros::c::task_delay(500);
	
	console.println("Loading Cata\n");

	// Load cata until brightness is lower than threshold
	while(cataLineSensor.get_value() > 2400) {
		catapult.move_voltage(8000);
	}

	// Vibrate controller
	controller.rumble("..");

	// Stop catapult and hold position
	catapult.move_voltage(0);

	// Set cataLoaded to true
	cataLoaded = true;
}

/**
 * @brief Fires the catapult if it is loaded.
 * 
 * If the catapult is loaded, this function will fire the catapult by moving the catapult motor at 12000 voltage for 200ms and then stopping the motor. 
 * It will also set the cataLoaded variable to false.
 * 
 */
void fireCatapult() {
	if (cataLoaded == true) {
		console.println("Firing Cata\n");

		// Fire cata
		catapult.move_voltage(12000);

		// Delay and brake motors
		pros::delay(200);
		catapult.move_voltage(0);

		// Set cataLoaded to false
		cataLoaded = false;
	}
}