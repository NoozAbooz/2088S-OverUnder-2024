#include "main.h"

bool wingsToggle = false;

// Refresh wing status
void refreshWings() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    	wingsToggle = !wingsToggle; 

		if(wingsToggle == true) {
			moveWings(true);
		} else {
			moveWings(false);
		}
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