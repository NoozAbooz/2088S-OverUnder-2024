#include "main.h"

// Intake
void spinIntake() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      intake.move_voltage(10000);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      intake.move_voltage(-12000);
    } else {
      intake.move_voltage(0);
    }
}