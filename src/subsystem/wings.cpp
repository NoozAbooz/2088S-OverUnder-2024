#include "main.h"

// Refresh wing status
void refreshWings() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      wingsPiston.extend();
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      wingsPiston.retract();
    }
}