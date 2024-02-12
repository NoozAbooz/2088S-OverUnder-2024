#include "main.h"

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