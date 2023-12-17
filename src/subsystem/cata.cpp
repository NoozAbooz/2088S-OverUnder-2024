#include "main.h"

// Catapult
bool cataLoaded = false;
bool cataLock = false;

/**
 * @brief Refreshes the catapult subsystem by checking for button presses and locking/unlocking the catapult.
 * 
 */
void refreshCatapult() {
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		catapult.move_voltage(10000);
	}
	
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) && !controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		fireCatapult();
		if(cataLock == false) {
			pros::Task loadCataTask(loadCatapult);
		}
	
	} else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) && !controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
	  	pros::Task loadCataTask(loadCatapult);
	}

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
		cataLock = !cataLock;
		controller.rumble("-.-");
		console.printf("Cata lock: %d\n", cataLock);
	}

	
}

/**
 * Loads the catapult until the brightness of the line sensor is lower than the threshold.
 * Sets cataLoaded to true and vibrates the controller when finished.
 */
void loadCatapult() {
	pros::c::task_delay(500);
	
	// Load cata until brightness is lower than threshold
	while(cataLineSensor.get_value() > 2500) {
		catapult.move_voltage(12000);
	}

	// Stop catapult and hold position
	catapult.move_voltage(0);

	// Vibrate controller
	controller.rumble("..");

	// Set cataLoaded to true
	cataLoaded = true;
	console.println("Cata loaded");
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
		// Fire cata
		catapult.move_voltage(10000);

		// Set cataLoaded to false
		cataLoaded = false;
		console.println("Cata fired");
	}
}