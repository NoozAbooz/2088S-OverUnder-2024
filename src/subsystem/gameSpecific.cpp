#include "deviceGlobals.hpp"
#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

// Wings
bool leftWingToggle = false;
bool rightWingToggle = false;
bool tailToggle = true;

// Refresh wing status
void refreshWings() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
    	leftWingToggle = !leftWingToggle; 
		leftWingPiston.set_value(leftWingToggle);
    }

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
    	rightWingToggle = !rightWingToggle; 
		rightWingPiston.set_value(rightWingToggle);
    }

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    	tailToggle = !tailToggle;
		tailPiston.set_value(tailToggle);
    }
}

// Slapper
void refreshSlapper() {
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		slapper.move_voltage(12000);
	} else {
		slapper.move_voltage(0);
	}
}

// Lift
// void ezCTier() {
// 	pros::delay(800);
// 	while(inertial.get_roll() > 5){
// 		tailPiston.set_value(true);
// 	}
// 	tailPiston.set_value(false);
// }
bool liftToggle = false;

// Refresh lift status
void refreshLift() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    	liftToggle = !liftToggle; 
		liftPiston.set_value(liftToggle);
		
		// if(liftToggle == false){
		// 	tailPiston.set_value(false);
		// }
    }
}