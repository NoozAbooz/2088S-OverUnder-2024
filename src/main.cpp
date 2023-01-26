#include "main.h"
#include <string>

void opcontrol() {
	bool intakeSwitch = false;

	while(true) {
		// Drive code
    	int power = controller.get_analog(ANALOG_LEFT_Y);
    	int turn = controller.get_analog(ANALOG_RIGHT_X);
    	int left = (power - turn) * (12000 / 127);
    	int right = (power + turn) * (12000 / 127);
    	frontLeft.move_voltage(left);
		backLeft.move_voltage(left);
    	frontRight.move_voltage(right);
		backRight.move_voltage(right);

		// Subsystem trigger
     	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      		intake.move_voltage(12000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
	  		intake.move_voltage(-12000);
		} else {
		    intake.brake();
		}
		
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      		flywheel.move_voltage(12000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			flywheel.move_voltage(-12000);
		} else {
			flywheel.brake();
      	}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      		roller.move_voltage(3000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
			roller.move_voltage(-3000);
		} else {
		    roller.brake();
		}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      		expansion.move_voltage(12000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			expansion.move_voltage(-12000);
		} else {
			expansion.brake();
      	}
		
		controller.print(1, 0, "%.0f RPM | %.0f°C     ", 100 * round((flywheel.get_actual_velocity() * 5)/100), flywheel.get_temperature());

		pros::delay(10);
  	}
}