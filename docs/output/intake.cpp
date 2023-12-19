#include "globals.hpp"

bool intakeToggle = false;

// Intake
void refreshIntake() {
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		intake.move_voltage(9000);
	} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		intake.move_voltage(-12000);
	} else {
		intake.brake();
	}

	if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    	intakeToggle = !intakeToggle;

		if(intakeToggle == true) {
			intakePiston.extend();
			console.println("Intake Extended");
		} else {
			intakePiston.retract();
			console.println("Intake Retracted");
		}
    }
}