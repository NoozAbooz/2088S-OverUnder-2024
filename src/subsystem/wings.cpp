#include "main.h"

// Refresh wing status
void refreshWings() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      leftWing.extend();
      rightWing.extend();
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      leftWing.retract();
      rightWing.retract();
    }
}