#include "main.h"

// Catapult
bool cataLoaded = false;

void refreshCatapult() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      fireCatapult();
      loadCatapult();
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      loadCatapult();
    }
}

// Reload the catapult
void loadCatapult() {
	// Change LED colour
	bodyLED.set_all(0xFFD972);
	bodyLED.update();
	
	// Load cata until brightness is lower than threshold
	while(cataPosition.get_value() > 2700) {
    	catapult.move_voltage(12000);
	}

	// Stop catapult and hold position
	catapult.move_voltage(0);

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