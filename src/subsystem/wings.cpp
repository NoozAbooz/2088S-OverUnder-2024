#include "main.h"

bool wingsToggle = false;

// Refresh wing status
void refreshWings() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
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
    	wingPiston.retract();
    	wingsToggle = false;
		console.println("Wings retracted");
  	} else {
    	wingPiston.extend();
    	wingsToggle = true;
		console.println("Wings extended");
  	}
}