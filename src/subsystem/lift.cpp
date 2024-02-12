#include "main.h"

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

