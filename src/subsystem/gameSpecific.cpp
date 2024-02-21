#include "main.h"

// Wings
bool wingsToggle = false;
bool tailToggle = true;

// Refresh wing status
void refreshWings() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    	wingsToggle = !wingsToggle; 
		wingsPiston.set_value(wingsToggle);

		printf("wingsPiston.set_value(%d);\n", !wingsToggle);
    }

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    	tailToggle = !tailToggle;
		tailPiston.set_value(tailToggle);

		printf("tailPiston.set_value(%d);\n", tailToggle);
    }
}

// Slapper
void refreshSlapper() {
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		slapper.move_voltage(12000);
	} else {
		slapper.move_voltage(0);
	}
}

// Lift
bool liftToggle = false;

// Refresh lift status
void refreshLift() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    	liftToggle = !liftToggle; 

		if(liftToggle == true) {
			liftPiston.set_value(true);
			controller.rumble("---");
		} else {
			liftPiston.set_value(false);
			controller.rumble("..");
		}
    }

	
}