#include "main.h"
#include "globals.hpp"

bool wingsToggle = false;

// Refresh wing status
void refreshWings() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    	  wingsToggle = !wingsToggle; 
    }

    if(wingsToggle == true) {
		wingPiston.extend();
	} else {
		wingPiston.retract();
	}
}

void toggleWings(bool status) {
  	if (status == false) {
    	wingPiston.retract();
    	wingsToggle = false;
  	} else {
    	wingPiston.extend();
    	wingsToggle = true;
  	}
}
