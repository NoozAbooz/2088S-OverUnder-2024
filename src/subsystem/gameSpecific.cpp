#include "deviceGlobals.hpp"
#include "main.h"

// Wings
bool leftWingToggle = false;
bool rightWingToggle = false;
bool tailToggle = true;

// Refresh wing status
void refreshWings() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    	leftWingToggle = !leftWingToggle; 
		leftWingPiston.set_value(leftWingToggle);
    }

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    	rightWingToggle = !rightWingToggle; 
		rightWingPiston.set_value(rightWingToggle);
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
bool ptoToggle = false;

// Refresh lift status
void refreshLift() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
    	liftToggle = !liftToggle; 
		liftPiston.set_value(liftToggle);
    }

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
    	ptoToggle = !ptoToggle; 
		ptoPiston.set_value(ptoToggle);
    }

}