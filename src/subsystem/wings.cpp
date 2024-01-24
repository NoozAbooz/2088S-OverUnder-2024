#include "abstractGlobals.hpp"
#include "deviceGlobals.hpp"
#include "main.h"

bool wingsToggle = false;
bool tailToggle = true;

// Refresh wing status
void refreshWings() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    	wingsToggle = !wingsToggle; 

		moveWings(wingsToggle);
    }

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    	tailToggle = !tailToggle;

		tailPiston.set_value(tailToggle);
    }
}

void moveWings(bool status) {
  	if (status == false) {
    	wingsPiston.set_value(false);
    	wingsToggle = false;
  	} else {
    	wingsPiston.set_value(true);
    	wingsToggle = true;
  	}
}