#include "main.h"
#include "globals.hpp"

bool wingsToggle = false;

// Refresh wing status
void refreshWings() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    	  wingsToggle = !wingsToggle; 
    }

    if(wingsToggle == true) {
		toggleWings(true);
	} else {
		toggleWings(false);
	}
}

void toggleWings(bool status) {
  	if (status == false) {
    	wingPiston.retract();
    	wingsToggle = false;

		printf("Wings Extended\n");
  	} else {
    	wingPiston.extend();
    	wingsToggle = true;

		printf("Wings Retracted\n");
  	}
}
