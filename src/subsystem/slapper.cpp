#include "main.h"

void refreshSlapper() {
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		slapper.move_voltage(12000);
	} else {
		slapper.move_voltage(0);
	}
}