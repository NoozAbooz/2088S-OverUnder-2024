#include "main.h"
#include "globals.hpp"

// Catapult
bool cataLoaded = false;
bool cataLock = false;

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
		controller.rumble("-");
		printf("Cata Locked\n");
	}
}

// Reload the catapult
void loadCatapult() {
	pros::c::task_delay(500);
	
	printf("Loading Cata\n");

	// Load cata until brightness is lower than threshold
	while(cataLineSensor.get_value() > 2400) {
		catapult.move_voltage(12000);
	}

	// Stop catapult and hold position
	catapult.move_voltage(0);

	// Set cataLoaded to true
	cataLoaded = true;

	// Vibrate controller
	controller.rumble(".");
}

// Fire catapult
void fireCatapult() {
	if (cataLoaded == true) {
		printf("Firing Cata\n");

		// Fire cata
		catapult.move_voltage(12000);

		// Delay and brake motors
		pros::delay(200);
		catapult.move_voltage(0);

		// Set cataLoaded to false
		cataLoaded = false;
	}
}