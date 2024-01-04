#include "declaration.hpp"
#include "main.h"

bool wingsToggle = false;

if (controller.pros::c::controller_get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    wingsToggle = !wingsToggle
	
	if (wingsToggle = true) {
		wings.set_value(true);
	} else {
		wings.set_value(false);
	}
}
